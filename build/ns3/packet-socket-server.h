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

#ifndef PACKET_SOCKET_SERVER_H
#define PACKET_SOCKET_SERVER_H

#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/packet-socket-address.h"
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/application.h"

#include "ns3/stats-module.h"

namespace ns3 {

class Socket;
class Packet;

/**
 * \ingroup socket
 *
 * \brief A server using PacketSocket.
 *
 * Receives packets using PacketSocket. It does not require (or use) IP.
 * The application has the same requirements as the PacketSocket for
 * what concerns the underlying NetDevice and the Address scheme.
 * It is meant to be used in ns-3 tests.
 *
 * Provides a "Rx" Traced Callback (received packets, source address)
 */
class PacketSocketServer : public Application
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  PacketSocketServer ();

  virtual ~PacketSocketServer ();

  /**
   * \brief set the local address and protocol to be used
   * \param addr local address
   */
  void SetLocal (PacketSocketAddress addr);
  void SetRemote (PacketSocketAddress addr);
  void SetEcho (bool echo);

protected:
  virtual void DoDispose (void);

private:

  virtual void StartApplication (void);
  virtual void StopApplication (void);

  /**
   * \brief Handle a packet received by the application
   * \param socket the receiving socket
   */
  void HandleRead (Ptr<Socket> socket);

  void Send (void);

  bool m_echo; // indicate if it echoes

  uint32_t m_pktRx;    //!< The number of received packets
  uint32_t m_bytesRx;  //!< Total bytes received

  Ptr<Socket> m_socket; //!< Socket
  Ptr<Socket> m_socket_echo; //!< Socket echo

  PacketSocketAddress m_peerAddress; //!< Remote peer address
  bool m_peerAddressSet; //!< Sanity check

  PacketSocketAddress m_localAddress; //!< Local address
  bool m_localAddressSet; //!< Sanity check

  EventId m_sendEvent;   //!< Event to send the next packet
  uint32_t m_sent;       //!< Counter for sent packets

  Ptr<Packet> m_packet; //!< Echo packet ready to be sent

  /// Traced Callback: sent packets, source address.
  TracedCallback<Ptr<const Packet>, const Address &> m_txTrace;

  /// Traced Callback: received packets, source address.
  TracedCallback<Ptr<const Packet>, const Address &> m_rxTrace;
};

/*
//------------------------------------------------------
class TimestampTag : public Tag {
public:
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (TagBuffer i) const;
  virtual void Deserialize (TagBuffer i);

  // these are our accessors to our tag structure
  void SetTimestamp (Time time);
  Time GetTimestamp (void) const;

  void Print (std::ostream &os) const;

private:
  Time m_timestamp;

  // end class TimestampTag
};
*/
} // namespace ns3

#endif /* PACKET_SOCKET_SERVER_H */
