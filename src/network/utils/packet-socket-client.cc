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
#include "packet-socket-client.h"
#include <cstdlib>
#include <cstdio>

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("PacketSocketClient");
NS_OBJECT_ENSURE_REGISTERED(PacketSocketClient);

TypeId
PacketSocketClient::GetTypeId(void)
{
	static TypeId tid = TypeId("ns3::PacketSocketClient")
			.SetParent<Application>()
			.AddConstructor<PacketSocketClient>()
			.AddAttribute("MaxPackets",
			"The maximum number of packets the application will send (zero means infinite)",
			UintegerValue(100),
			MakeUintegerAccessor(&PacketSocketClient::m_maxPackets),
			MakeUintegerChecker<uint32_t>())
			.AddAttribute("Interval",
			"The time to wait between packets", TimeValue(Seconds(1.0)),
			MakeTimeAccessor(&PacketSocketClient::m_interval),
			MakeTimeChecker())
			.AddAttribute("PacketSize",
			"Size of packets generated (bytes).",
			UintegerValue(1024),
			MakeUintegerAccessor(&PacketSocketClient::m_size),
			MakeUintegerChecker<uint32_t>())
			.AddTraceSource("Rx", "A packet has been received",
			MakeTraceSourceAccessor(&PacketSocketClient::m_rxTrace))
			.AddTraceSource("Tx", "A packet has been sent",
			MakeTraceSourceAccessor(&PacketSocketClient::m_txTrace))
					;
	return tid;
}

PacketSocketClient::PacketSocketClient()
{
	NS_LOG_FUNCTION(this);
	m_sent = 0;
	m_socket = 0;
	m_socket_echo = 0;
	m_sendEvent = EventId();
	m_peerAddressSet = false;
	m_localAddressSet = false;
}

PacketSocketClient::~PacketSocketClient()
{
	NS_LOG_FUNCTION(this);
}

void
PacketSocketClient::SetRemote(PacketSocketAddress addr)
{
	NS_LOG_FUNCTION(this << addr);
	m_peerAddress = addr;
	m_peerAddressSet = true;
}

void
PacketSocketClient::SetLocal(PacketSocketAddress addr)
{
	NS_LOG_FUNCTION(this << addr);
	m_localAddress = addr;
	m_localAddressSet = true;
}

void
PacketSocketClient::DoDispose(void)
{
	NS_LOG_FUNCTION(this);
	Application::DoDispose();
}

void
PacketSocketClient::StartApplication(void)
{
	NS_LOG_FUNCTION(this);
	NS_ASSERT_MSG(m_peerAddressSet, "Peer address not set");

	if (m_socket == 0)
	{
		TypeId tid = TypeId::LookupByName("ns3::PacketSocketFactory");
		m_socket = Socket::CreateSocket(GetNode(), tid);

		m_socket->Bind(m_peerAddress);
		m_socket->Connect(m_peerAddress);
	}

	m_socket->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> >());
	m_sendEvent = Simulator::ScheduleNow(&PacketSocketClient::Send, this);

	if (m_socket_echo == 0)
	{
		TypeId tid = TypeId::LookupByName("ns3::PacketSocketFactory");
		m_socket_echo = Socket::CreateSocket(GetNode(), tid);

		m_socket_echo->Bind(m_localAddress);
	}

	m_socket_echo->SetRecvCallback(MakeCallback(&PacketSocketClient::HandleRead, this));

}

void
PacketSocketClient::StopApplication(void)
{
	NS_LOG_FUNCTION(this);
	Simulator::Cancel(m_sendEvent);
	m_socket->Close();
	m_socket_echo->SetRecvCallback(MakeNullCallback<void, Ptr<Socket> >());
	m_socket_echo->Close();
}

void
PacketSocketClient::Send(void)
{
	NS_LOG_FUNCTION(this->GetNode()->GetId());
	NS_ASSERT(m_sendEvent.IsExpired());

	Ptr<Packet> p = Create<Packet>(m_size);

	TimestampTag timestamp;
	timestamp.SetTimestamp(Simulator::Now());
	p->AddByteTag(timestamp);

	std::stringstream peerAddressStringStream;
	peerAddressStringStream << PacketSocketAddress::ConvertFrom(m_peerAddress);

	if ((m_socket->Send(p)) >= 0)
	{
		NS_LOG_INFO("TraceDelay TX " << m_size << " bytes to "
				<< peerAddressStringStream.str() << " Uid: "
				<< p->GetUid() << " Time: "
				<< (Simulator::Now()).GetSeconds());
	}
	else
	{
		NS_LOG_INFO("Error while sending " << m_size << " bytes to "
				<< peerAddressStringStream.str());
	}
	m_sent++;

	if ((m_sent < m_maxPackets) || (m_maxPackets == 0))
	{
		m_txTrace(p, m_peerAddress);
		m_sendEvent = Simulator::Schedule(m_interval, &PacketSocketClient::Send, this);
	}
}

void
PacketSocketClient::HandleRead(Ptr<Socket> socket)
{
	NS_LOG_FUNCTION(this->GetNode()->GetId() << socket->GetNode()->GetId());
	Ptr<Packet> packet;
	Address from;
	while ((packet = socket->RecvFrom(from)))
	{
		if (PacketSocketAddress::IsMatchingType(from))
		{
			/*
			 std::ostringstream ss_Address_From;
			 ss_Address_From << from;
			 std::string str_Address_From = ss_Address_From.str();
			 std::ostringstream ss_Address_Peer;
			 ss_Address_Peer << m_peerAddress;
			 std::string str_Address_Peer = ss_Address_Peer.str();
			 if (str_Address_From.substr(str_Address_From.length() - 2) == str_Address_From.substr(str_Address_Peer.length() - 2))
			 */
			m_rxTrace(packet, from);
		}
	}
}

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

} // Namespace ns3
