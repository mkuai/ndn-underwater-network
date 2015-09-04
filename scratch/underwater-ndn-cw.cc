// NDN for underwater using MAC-CW(Int) and MAC-RC(Data)
// Meng Kuai
// 7/22/2015

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

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>

// for tracer

#include "ns3/ndnSIM/utils/tracers/ndn-app-delay-tracer.hpp"
#include "ns3/ndnSIM/utils/tracers/ndn-l3-rate-tracer.hpp"
#include "ns3/ndnSIM/utils/tracers/l2-rate-tracer.hpp"
#include "ns3/ndnSIM/utils/tracers/ndn-cs-tracer.hpp"

namespace ns3
{

using namespace boost;
using namespace std;
using namespace nfd;
NS_LOG_COMPONENT_DEFINE("Experiment");

int main(int argc, char *argv[])
{
	// Assign log component
	//LogComponentEnable("Experiment", LOG_ALL);
	//LogComponentEnable("ndn.NetDeviceFace", LOG_ALL);

	//LogComponentEnable("ndn.StackHelper", LOG_ALL);
	//LogComponentEnable("ndn.Consumer", LOG_ALL);

	//LogComponentEnable("nfd.Forwarder", LOG_ALL);
	//LogComponentEnable("ndn.L3Protocol", LOG_ALL);

	//LogComponentEnable("UanMacAloha", LOG_ALL);
	//LogComponentEnable("UanMacCw", LOG_ALL);
	//LogComponentEnable("UanMacRcGw", LOG_ALL);

	//LogComponentEnable("DeviceEnergyModel", LOG_ALL);
	//LogComponentEnable("UanChannel", LOG_ALL);
	//LogComponentEnable("UanPhyGen", LOG_ALL);
	//LogComponentEnable("UanPropModelIdeal", LOG_ALL);
	//LogComponentEnable("UanPhyDual", LOG_ALL);

	CommandLine cmd;

	uint32_t run = 1;  // not used right now
	cmd.AddValue("run", "Run", run);

	uint32_t sim_time = 10000;
	cmd.AddValue("time", "simulation time", sim_time);

	uint32_t n_NumOfMasters = 1;
	cmd.AddValue("numberOfMasters", "number of masters", n_NumOfMasters);

	uint32_t n_NumOfSensors = 1;
	cmd.AddValue("numberOfSensors", "number of sensors", n_NumOfSensors);

	uint32_t n_Depth = 200;
	cmd.AddValue("WaterDepth", "water depth", n_Depth);

	uint32_t n_Distance = 3000;
	cmd.AddValue("distance", "min distance between sensors", n_Distance);

	uint32_t n_ProducerId = 1;
	cmd.AddValue("producer", "producer", n_ProducerId);

	uint32_t n_ConsumerId = 0;  // not used right now
	cmd.AddValue("consumer", "consumer", n_ConsumerId);

	double d_Frequency1 = 0.005;  // sending data interval = 200
	cmd.AddValue("frequency1", "frequency1", d_Frequency1);

	double d_Frequency2 = 0.001;  // sending data interval = 200
	cmd.AddValue("frequency2", "frequency2", d_Frequency2);

	double d_Frequency3 = 0.001;  // sending data interval = 200
	cmd.AddValue("frequency3", "frequency3", d_Frequency3);

	uint32_t n_PacketSize = 7;  // data packet size (byte)
	cmd.AddValue("size", "packet size", n_PacketSize);

	cmd.Parse(argc, argv);

	Config::SetGlobal("RngRun", IntegerValue(run));

	// =================================================================
	// 1. Install Mobility model

	NS_LOG_INFO("1. Installing mobility model");

	// create nodes

	NodeContainer nodes_Masters;
	nodes_Masters.Create(n_NumOfMasters);

	NodeContainer nodes_Sensors;
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

	// install uan for masters
	for (NodeContainer::Iterator i = nodes_Masters.Begin(); i != nodes_Masters.End(); i++)
	{
		Ptr<Node> node = *i;
		Ptr<UanNetDevice> device = uan.Install(node, channel);
	}

	// install uan for sensors
	for (NodeContainer::Iterator i = nodes_Sensors.Begin(); i != nodes_Sensors.End(); i++)
	{
		Ptr<Node> node = *i;
		Ptr<UanNetDevice> device = uan.Install(node, channel);
	}

	// =================================================================
	// 3. Install NDN stack for all nodes

	NS_LOG_INFO("3. Installing NDN stack");
	ndn::StackHelper ndnHelper;
	ndnHelper.SetDefaultRoutes(true);
	ndnHelper.SetOldContentStore("ns3::ndn::cs::Lru", "MaxSize", "1000");
	ndnHelper.InstallAll();

	ndn::StrategyChoiceHelper::InstallAll("/Tuscaloosa/UA/SEC", "/localhost/nfd/strategy/broadcast");

	// =================================================================
	// 4. Set up NDN applications

	NS_LOG_INFO("4. Installing NDN Applications");

	// define producer app in sensor nodes

	ndn::AppHelper producerHelper("ns3::ndn::Producer");
	producerHelper.SetPrefix("/Tuscaloosa/UA/SEC");
	producerHelper.SetAttribute("PayloadSize", UintegerValue(n_PacketSize));
	producerHelper.Install(nodes_Sensors.Get(n_ProducerId - 1));
	//producerHelper.Install(nodes_Sensors);

	// define consumer app: run 3 apps in master node

	// App 1
	//ndn::AppHelper consumerHelper("ns3::ndn::ConsumerBatches");
	ndn::AppHelper consumerHelper1("ns3::ndn::ConsumerCbr");
	consumerHelper1.SetPrefix("/Tuscaloosa/UA/SEC");
	consumerHelper1.SetAttribute("Frequency", DoubleValue(d_Frequency1));
	//consumerHelper1.SetAttribute("Randomize", StringValue("uniform"));

	//consumerHelper.SetAttribute("Batches", StringValue("100s 1"));
	consumerHelper1.SetAttribute("LifeTime", StringValue("20000s")); // LifeTime for interest packet
	consumerHelper1.SetAttribute("RetxTimer", StringValue("20000")); // Timeout defining how frequent retransmission timeouts should be checked
	consumerHelper1.Install(nodes_Masters);

	// App 2
	ndn::AppHelper consumerHelper2("ns3::ndn::ConsumerCbr");
	consumerHelper2.SetPrefix("/Tuscaloosa/UA/SEC");
	consumerHelper2.SetAttribute("Frequency", DoubleValue(d_Frequency2));
	//consumerHelper2.SetAttribute("Randomize", StringValue("uniform"));

	consumerHelper2.SetAttribute("BeginTime", IntegerValue(650));
	consumerHelper2.SetAttribute("LifeTime", StringValue("20000s")); // LifeTime for interest packet
	consumerHelper2.SetAttribute("RetxTimer", StringValue("20000")); // Timeout defining how frequent retransmission timeouts should be checked
	consumerHelper2.Install(nodes_Masters);

	// App 3
	ndn::AppHelper consumerHelper3("ns3::ndn::ConsumerCbr");
	consumerHelper3.SetPrefix("/Tuscaloosa/UA/SEC");
	consumerHelper3.SetAttribute("Frequency", DoubleValue(d_Frequency3));
	//consumerHelper3.SetAttribute("Randomize", StringValue("uniform"));

	consumerHelper3.SetAttribute("LifeTime", StringValue("20000s")); // LifeTime for interest packet
	consumerHelper3.SetAttribute("RetxTimer", StringValue("20000")); // Timeout defining how frequent retransmission timeouts should be checked
	//consumerHelper3.Install(nodes_Masters);

	// =================================================================
	// 5. Set up tracer

	NS_LOG_INFO("5. Set up tracer");

	// obtain data about for delays between issuing Interest and receiving corresponding Data packet.
	ndn::AppDelayTracer::InstallAll("results/app-delays-trace.txt");

	// Tracing the rate in bytes and in number of packets of Interest/Data packets forwarded by an NDN node
	//ndn::L3RateTracer::InstallAll("results/l3-rate-trace.txt", Seconds(1));

	// traces only packet drop on layer 2 (e.g., due to transmission queue overflow).
	//L2RateTracer::InstallAll("results/l2-rate-trace.txt", Seconds(1));

	// obtain statistics of cache hits/cache misses on simulation nodes.
	//ndn::CsTracer::InstallAll("results/cs-trace.txt", Seconds(1));

	// =================================================================
	// run the simulation
	Simulator::Stop(Seconds(sim_time));
	NS_LOG_INFO("Starting");
	Simulator::Run();
	NS_LOG_INFO("Done");
	Simulator::Destroy();

	return 0;
}

} // namespace ns3

int main(int argc, char* argv[])
{
	return ns3::main(argc, argv);
}
