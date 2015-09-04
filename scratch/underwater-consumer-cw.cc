#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/uan-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/ndnSIM-module.h"
#include "ns3/ns2-mobility-helper.h"
#include "ns3/stats-module.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

#include <iostream>
#include <fstream>

namespace ns3
{

using namespace boost;
using namespace std;
NS_LOG_COMPONENT_DEFINE("Experiment");

uint32_t m_bytesTotal = 0;
uint32_t m_TxTotal = 0;
uint32_t m_RxTotal = 0;
Ptr<TimeMinMaxAvgTotalCalculator> m_delay = 0;
ofstream output;
ofstream output_tx;

NodeContainer nodes_Sensors;
uint32_t n_ProducerId = 0;

void
SendPacket(Ptr<const Packet> packet, const Address & address)
{
	m_TxTotal++;
	NS_LOG_INFO("[Tx] " << Simulator::Now().GetSeconds() << "  pid=" << packet->GetUid() << ", size=" << packet->GetSize());
}

void
ReceivePacket(Ptr<const Packet> packet, const Address & add_Sender)
{
	m_RxTotal++;
	m_bytesTotal += packet->GetSize();
	TimestampTag timestamp;
	Time tx;
	if (packet->FindFirstMatchingByteTag(timestamp))
	{
		tx = timestamp.GetTimestamp();
		if (m_delay != 0)
		{
			m_delay->Update(Simulator::Now() - tx);
		}
	}

	Address add_Producer = nodes_Sensors.Get(n_ProducerId - 1)->GetDevice(0)->GetAddress();
	std::ostringstream ss_Address;
	ss_Address << add_Producer;
	string str_Add_Producer = ss_Address.str();
	ss_Address << add_Sender;
	string str_Add_Sender = ss_Address.str();

	//NS_LOG_INFO(str_Add_Producer.substr(str_Add_Producer.length() - 2) << "; " << str_Add_Sender.substr(str_Add_Sender.length() - 2));

	//if (str_Add_Producer.substr(str_Add_Producer.length() - 2) == str_Add_Sender.substr(str_Add_Sender.length() - 2))
	//{
	NS_LOG_INFO("[Rx] " << Simulator::Now().GetSeconds() << "  pid=" << packet->GetUid() << ", size=" << packet->GetSize()
			<< ", delay=" << (Simulator::Now() - tx).GetSeconds() << ", total=" << m_bytesTotal << ", address=" << str_Add_Sender<< ", "
			<<str_Add_Producer);
	output << Simulator::Now().GetSeconds() << "\t" << (Simulator::Now() - tx).GetSeconds()
			<< "\t" << packet->GetSize() << "\t" << m_bytesTotal << "\n";
	//}

}

int main(int argc, char *argv[])
{
	m_delay = CreateObject<TimeMinMaxAvgTotalCalculator>();
	m_delay->SetKey("delay");
	m_delay->SetContext(".");

	output.open("results/output.txt");
	output << "Time\tDelay\tSize\tTotalSize\n";

	// Assign log component
	//LogComponentEnable("Experiment", LOG_ALL);

	//LogComponentEnable("PacketSocketServer", LOG_ALL);
	//LogComponentEnable("PacketSocketClient", LOG_ALL);
	//LogComponentEnable("OnOffApplication", LOG_ALL);
	//LogComponentEnable("Socket", LOG_ALL);

	//LogComponentEnable("ndn.RttEstimator", LOG_ALL);
	//LogComponentEnable("ndn.L3Protocol", LOG_ALL);

	//LogComponentEnable("UanMacCw", LOG_ALL);
	//LogComponentEnable("UanTransducerHd", LOG_ALL);
	//LogComponentEnable("DeviceEnergyModel", LOG_ALL);
	//LogComponentEnable("UanChannel", LOG_ALL);
	//LogComponentEnable("UanPhyGen", LOG_ALL);
	//LogComponentEnable("UanPropModelIdeal", LOG_ALL);
	//LogComponentEnable("UanPhyDual", LOG_ALL);

	CommandLine cmd;

	uint32_t run = 1;  // not used right now
	cmd.AddValue("run", "Run", run);

	uint32_t sim_time = 5000;
	cmd.AddValue("time", "simulation time", sim_time);

	uint32_t n_NumOfMasters = 1;
	cmd.AddValue("numberOfMasters", "number of masters", n_NumOfMasters);

	uint32_t n_NumOfSensors = 1;
	cmd.AddValue("numberOfSensors", "number of sensors", n_NumOfSensors);

	uint32_t n_Depth = 200;
	cmd.AddValue("WaterDepth", "water depth", n_Depth);

	uint32_t n_Distance = 3000; // not used right now
	cmd.AddValue("distance", "min distance between sensors", n_Distance);

	n_ProducerId = 1;  // random picked up by script: 1 ~ sensorNum
	cmd.AddValue("producer", "producer", n_ProducerId);

	uint32_t n_ConsumerId = 0;  // not used right now
	cmd.AddValue("consumer", "consumer", n_ConsumerId);

	uint32_t n_Interval1 = 300;  // sending data interval
	cmd.AddValue("interval1", "interval1", n_Interval1);

	uint32_t n_Interval2 = 600;  // sending data interval
	cmd.AddValue("interval2", "interval2", n_Interval2);

	uint32_t n_Interval3 = 800;  // sending data interval
	cmd.AddValue("interval3", "interval3", n_Interval3);

	uint32_t n_PacketSize = 7;  // data packet size
	cmd.AddValue("size", "packet size", n_PacketSize);

	cmd.Parse(argc, argv);

	Config::SetGlobal("RngRun", IntegerValue(run));

	// =================================================================
	// 1. Install Mobility model

	NS_LOG_INFO("1. Installing mobility model");

	// create nodes

	NodeContainer nodes_Masters;
	nodes_Masters.Create(n_NumOfMasters);

	nodes_Sensors.Create(n_NumOfSensors);

	MobilityHelper mobility;
	mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");

	// set positions for masters
	Ptr<ListPositionAllocator> positionAlloc_Masters = CreateObject<ListPositionAllocator>();
	positionAlloc_Masters->Add(Vector(0, 0, n_Depth));
	mobility.SetPositionAllocator(positionAlloc_Masters);
	mobility.Install(nodes_Masters);

	// set positions for sensors

	Ptr<ListPositionAllocator> positionAlloc_Sensors = CreateObject<ListPositionAllocator>();
	positionAlloc_Sensors->Add(Vector(n_Distance * (-1.0), n_Distance, 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance * (-0.5), n_Distance * 0.5, 0));
	positionAlloc_Sensors->Add(Vector(n_Distance * (-1.0), 0.0, 0.0));
	positionAlloc_Sensors->Add(Vector(0.0, n_Distance, 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance * (-0.5), n_Distance * (-0.5), 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance * 0.5, n_Distance * 0.5, 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance * (-1.0), n_Distance * (-1.0), 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance, n_Distance, 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance * 0.5, n_Distance * (-0.5), 0.0));
	positionAlloc_Sensors->Add(Vector(0.0, n_Distance * (-1.0), 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance, 0.0, 0.0));
	positionAlloc_Sensors->Add(Vector(n_Distance, n_Distance * (-1.0), 0.0));
	mobility.SetPositionAllocator(positionAlloc_Sensors);
	mobility.Install(nodes_Sensors);

	// =================================================================
	// 2. Configure and install L2

	NS_LOG_INFO("2. Installing UAN");

	UanHelper uan;
	Ptr<UanPropModelThorp> prop = CreateObjectWithAttributes<UanPropModelThorp>();
	Ptr<UanNoiseModel> noise = CreateObjectWithAttributes<UanNoiseModelDefault>(); // turb, wind, ship, thermal
	Ptr<UanChannel> channel = CreateObjectWithAttributes<UanChannel>(
			"PropagationModel", PointerValue(prop),
			"NoiseModel", PointerValue(noise));

	ObjectFactory obf;
	obf.SetTypeId("ns3::UanPhyPerGenDefault");
	Ptr<UanPhyPer> per = obf.Create<UanPhyPer>();
	obf.SetTypeId("ns3::UanPhyCalcSinrDefault");
	Ptr<UanPhyCalcSinr> sinr = obf.Create<UanPhyCalcSinr>();

	UanTxMode mode;
	mode = UanTxModeFactory::CreateMode(
			UanTxMode::FSK, // ModulationType
			80, // data rate of the transmit mode (bits per second)
			80, // physical signaling rate (symbols per second)
			25000, // transmission center frequency (Hz): used in Thorp Loss Model
			80, // transmission signal bandwidth (Hz)
			2, // the number of constellation points in the modulation scheme
			"Default mode"); // mode name
	UanModesList myModes;
	myModes.AppendMode(mode);

	uan.SetPhy("ns3::UanPhyGen",
			"PerModel", PointerValue(per), // Functor to calculate PER based on SINR and TxMode.
			"SinrModel", PointerValue(sinr), // Functor to calculate SINR based on pkt arrivals and modes.
			"SupportedModes", UanModesListValue(myModes), // List of modes supported by this PHY
			"RxThreshold", DoubleValue(10), // Required SNR for signal acquisition in dB
			"TxPower", DoubleValue(190), // Transmission output power in dB
			"RxGain", DoubleValue(0)); // Gain added to incoming signal at receiver

	uan.SetMac("ns3::UanMacCw",
			"CW", UintegerValue(12),
			"SlotTime", TimeValue(Seconds(1)));

	// define socket (sensors --> master node)
	PacketSocketAddress socket_Master;
	socket_Master.SetAllDevices();
	socket_Master.SetProtocol(0);

	// install uan for masters
	for (NodeContainer::Iterator i = nodes_Masters.Begin(); i != nodes_Masters.End(); i++)
	{
		Ptr<Node> node = *i;
		Ptr<UanNetDevice> device = uan.Install(node, channel);
		socket_Master.SetPhysicalAddress(device->GetAddress());
	}

	// define socket (master node --> sensors)
	PacketSocketAddress socket_Sensors[n_NumOfSensors];
	for (uint32_t i = 0; i < n_NumOfSensors; i++)
	{
		socket_Sensors[i].SetAllDevices();
		socket_Sensors[i].SetProtocol(0);
	}

	// install uan for sensors
	for (NodeContainer::Iterator i = nodes_Sensors.Begin(); i != nodes_Sensors.End(); i++)
	{
		Ptr<Node> node = *i;
		Ptr<UanNetDevice> device = uan.Install(node, channel);
		socket_Sensors[node->GetId() - 1].SetPhysicalAddress(device->GetAddress());
	}

	// 3. Install IP stack for all nodes
	NS_LOG_INFO("3. Installing Network stack");

	PacketSocketHelper packetSocket;
	packetSocket.Install(nodes_Masters);
	packetSocket.Install(nodes_Sensors);

	// 4. Install App
	NS_LOG_INFO("4. Installing Applications");

	// master node
	for (NodeContainer::Iterator i = nodes_Sensors.Begin(); i != nodes_Sensors.End(); i++)
	{
		Ptr<Node> node = *i;
		Ptr<PacketSocketClient> client1 = CreateObjectWithAttributes<PacketSocketClient>(
				"Interval", TimeValue(Seconds(n_Interval1)),
				"PacketSize", UintegerValue(n_PacketSize));
		Ptr<PacketSocketClient> client2 = CreateObjectWithAttributes<PacketSocketClient>(
				"Interval", TimeValue(Seconds(n_Interval2)),
				"PacketSize", UintegerValue(n_PacketSize));
		Ptr<PacketSocketClient> client3 = CreateObjectWithAttributes<PacketSocketClient>(
				"Interval", TimeValue(Seconds(n_Interval3)),
				"PacketSize", UintegerValue(n_PacketSize));

		client1->SetRemote(socket_Sensors[node->GetId() - 1]);
		client2->SetRemote(socket_Sensors[node->GetId() - 1]);
		client3->SetRemote(socket_Sensors[node->GetId() - 1]);
		client1->TraceConnectWithoutContext("Tx", MakeCallback(&SendPacket));
		client2->TraceConnectWithoutContext("Tx", MakeCallback(&SendPacket));
		client3->TraceConnectWithoutContext("Tx", MakeCallback(&SendPacket));

		Ptr<PacketSocketServer> server = CreateObject<PacketSocketServer>();
		server->SetLocal(socket_Sensors[node->GetId() - 1]);

		if (node->GetId() == n_ProducerId)
		{
			client1->SetLocal(socket_Master);
			client2->SetLocal(socket_Master);
			client3->SetLocal(socket_Master);
			client1->TraceConnectWithoutContext("Rx", MakeCallback(&ReceivePacket));
			//client2->TraceConnectWithoutContext("Rx", MakeCallback(&ReceivePacket));
			server->SetRemote(socket_Master);
			server->SetEcho(true);
			//server->TraceConnectWithoutContext("Rx", MakeCallback(&ReceivePacket));
			server->TraceConnectWithoutContext("Tx", MakeCallback(&SendPacket));
		}
		else
		{
			server->SetEcho(false);
		}

		client2->SetStartTime(Seconds(650));

		nodes_Masters.Get(0)->AddApplication(client1);
		nodes_Masters.Get(0)->AddApplication(client2);
		//nodes_Masters.Get(0)->AddApplication(client3);
		node->AddApplication(server);
	}

// =================================================================
// run the simulation
	Simulator::Stop(Seconds(sim_time));
	NS_LOG_INFO("Starting");
	Simulator::Run();
	NS_LOG_INFO("Done");
	Simulator::Destroy();

	//output << "\nSensor#: " << n_NumOfSensors << "\n";
	//output << "Interval(s): " << n_Interval << "\n";
	//output << "Tx#: " << m_TxTotal << "\n";
	//output << "Rx#: " << m_RxTotal << "\n";
	//output << "Loss(%): " << 1 - (float)m_RxTotal / m_TxTotal << "\n";
	output.close();

	output_tx.open("results/output_tx.txt");
	output_tx << m_TxTotal;
	output_tx.close();

	return 0;
}

} // namespace ns3

int main(int argc, char* argv[])
{
	return ns3::main(argc, argv);
}
