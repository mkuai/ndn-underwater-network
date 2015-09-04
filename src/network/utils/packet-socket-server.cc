/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2014 Universita' di Firenze
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Tommaso Pecorella <tommaso.pecorella@unifi.it>
 */

#include "ns3/log.h"
#include "ns3/nstime.h"
#include "ns3/packet-socket-address.h"
#include "ns3/packet-socket.h"
#include "ns3/packet-socket-factory.h"
#include "ns3/socket.h"
#include "ns3/simulator.h"
#include "ns3/socket-factory.h"
#include "ns3/packet.h"
#include "ns3/uinteger.h"
#include "ns3/abort.h"
#include "packet-socket-server.h"
#include <cstdlib>
#include <cstdio>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("PacketSocketServer");
NS_OBJECT_ENSURE_REGISTERED(PacketSocketServer);

TypeId
PacketSocketServer::GetTypeId(void)
{
	static TypeId tid = TypeId("ns3::PacketSocketServer")
			.SetParent<Application>()
			.AddConstructor<PacketSocketServer>()
			.AddTraceSource("Rx", "A packet has been received",
			MakeTraceSourceAccessor(&PacketSocketServer::m_rxTrace))
			.AddTraceSource("Tx", "A packet has been sent",
			MakeTraceSourceAccessor(&PacketSocketServer::m_txTrace))
					;
	return tid;
}

PacketSocketServer::PacketSocketServer()
{
	NS_LOG_FUNCTION(this);
	m_pktRx = 0;
	m_bytesRx = 0;
	m_sent = 0;
	m_socket = 0;
	m_socket_echo = 0;
	m_packet = 0;
	m_sendEvent = EventId();
	m_echo = false;
	m_localAddressSet = false;
	m_peerAddressSet = false;
}

PacketSocketServer::~PacketSocketServer()
{
	NS_LOG_FUNCTION(this);
}

void
PacketSocketServer::DoDispose(void)
{
	NS_LOG_FUNCTION(this);
	Application::DoDispose();
}

void
PacketSocketServer::StartApplication(void)
{
	NS_LOG_FUNCTION(this);
	NS_ASSERT_MSG(m_localAddressSet, "Local address not set");

	if (m_socket == 0)
	{
		TypeId tid = TypeId::LookupByName("ns3::PacketSocketFactory");
		m_socket = Socket::CreateSocket(GetNode(), tid);
		m_socket->Bind(m_localAddress);
	}

	m_socket->SetRecvCallback(MakeCallback(&PacketSocketServer::HandleRead, this));

	if (m_socket_echo == 0)
	{
		TypeId tid = TypeId::LookupByName("ns3::PacketSocketFactory");
		m_socket_echo = Socket::CreateSocket(GetNode(), tid);

		m_socket_echo->Bind(m_peerAddress);
		m_socket_echo->Connect(m_peerAddress);

	}
	//m_socket_echo->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> >());
}

void
PacketSocketServer::StopApplication(void)
{
	NS_LOG_FUNCTION(this);
	m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> >());
	m_socket->Close();
	m_socket_echo->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> >());
	m_socket_echo->Close();
}

void
PacketSocketServer::SetRemote(PacketSocketAddress addr)
{
	NS_LOG_FUNCTION(this << addr);
	m_peerAddress = addr;
	m_peerAddressSet = true;
}

void
PacketSocketServer::SetLocal(PacketSocketAddress addr)
{
	NS_LOG_FUNCTION(this << addr);
	m_localAddress = addr;
	m_localAddressSet = true;
}

void
PacketSocketServer::SetEcho(bool echo)
{
	NS_LOG_FUNCTION(this << echo);
	m_echo = echo;
}

void
PacketSocketServer::HandleRead(Ptr<Socket> socket)
{
	NS_LOG_FUNCTION(this->GetNode()->GetId() << socket->GetNode()->GetId());
	Ptr<Packet> packet;
	Address from;
	while ((packet = socket->RecvFrom(from)))
	{
		if (PacketSocketAddress::IsMatchingType(from))
		{
			m_pktRx++;
			m_bytesRx += packet->GetSize();
			NS_LOG_INFO("At time " << Simulator::Now ().GetSeconds ()
					<< "s packet sink received "
					<< packet->GetSize () << " bytes from "
					<< PacketSocketAddress::ConvertFrom (from) << ", uid: " << packet->GetUid()
					<< " total Rx " << m_pktRx << " packets"
					<< " and " << m_bytesRx << " bytes");
			m_rxTrace(packet, from);
			if (m_echo)
			{
				m_packet = packet;
				m_sendEvent = Simulator::ScheduleNow(&PacketSocketServer::Send, this);
			}
		}
	}
}

void
PacketSocketServer::Send(void)
{

	NS_LOG_FUNCTION(this->GetNode()->GetId());
	NS_ASSERT(m_sendEvent.IsExpired());

	TimestampTag timestamp;
	Time tx;
	if (m_packet->FindFirstMatchingByteTag(timestamp))
	{
		tx = timestamp.GetTimestamp();
	}

	Ptr<Packet> p = Create<Packet>(m_packet->GetSize());
	timestamp.SetTimestamp(tx);
	p->AddByteTag(timestamp);

	std::stringstream peerAddressStringStream;
	peerAddressStringStream << PacketSocketAddress::ConvertFrom(m_peerAddress);

	if ((m_socket_echo->Send(p)) >= 0)
	{
		NS_LOG_INFO("TraceDelay TX " << 10 << " bytes to "
				<< peerAddressStringStream.str() << " Uid: "
				<< p->GetUid() << " Time: "
				<< (Simulator::Now()).GetSeconds());
		m_txTrace(p, m_peerAddress);
	}
	else
	{
		NS_LOG_INFO("Error while sending " << 13 << " bytes to "
				<< peerAddressStringStream.str());
	}
	m_sent++;
}

/*
 //----------------------------------------------------------------------
 //-- TimestampTag
 //------------------------------------------------------
 TypeId
 TimestampTag::GetTypeId(void)
 {
 static TypeId tid = TypeId("TimestampTag")
 .SetParent<Tag>()
 .AddConstructor<TimestampTag>()
 .AddAttribute("Timestamp",
 "Some momentous point in time!",
 EmptyAttributeValue(),
 MakeTimeAccessor(&TimestampTag::GetTimestamp),
 MakeTimeChecker())
 ;
 return tid;
 }
 TypeId
 TimestampTag::GetInstanceTypeId(void) const
 {
 return GetTypeId();
 }

 uint32_t
 TimestampTag::GetSerializedSize(void) const
 {
 return 8;
 }
 void
 TimestampTag::Serialize(TagBuffer i) const
 {
 int64_t t = m_timestamp.GetNanoSeconds();
 i.Write((const uint8_t *) &t, 8);
 }
 void
 TimestampTag::Deserialize(TagBuffer i)
 {
 int64_t t;
 i.Read((uint8_t *) &t, 8);
 m_timestamp = NanoSeconds(t);
 }

 void
 TimestampTag::SetTimestamp(Time time)
 {
 m_timestamp = time;
 }
 Time
 TimestampTag::GetTimestamp(void) const
 {
 return m_timestamp;
 }

 void
 TimestampTag::Print(std::ostream &os) const
 {
 os << "t=" << m_timestamp;
 }
 */
} // Namespace ns3
