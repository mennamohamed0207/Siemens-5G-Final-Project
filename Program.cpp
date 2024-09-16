#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#include "Program.h"

void Program::generatePackets(const std::string &outputFile)
{
    std::ofstream out(outputFile);
    long long numberOfBursts = calculateNumberOfBursts();

    long long IFGs = handleIFGs();
    for (int i = 0; i < numberOfBursts; i++)
    {

        for (int j = 0; j < config.EthBurstSize; j++)
        {
            string destAddress = (config.EthDestAddress);
            string srcAddress = (config.EthSourceAddress);
            string ethernetType = "0800";
            string payload = "";
            int payloadSize = config.EthMaxPacketSize - (7 + 1 + 6 + 6 + 2 + 4 + config.EthMinNumOfIFGsPerPacket);
            while (payloadSize != 0)
            {
                payload += "00";
                payloadSize--;
            }
            Packet p(destAddress, srcAddress, "0800", payload); // EtherType 0x0800 for IPv4

            int IFGs = config.EthMinNumOfIFGsPerPacket;
            string AddedIFG = "";
            while (IFGs != 0)
            {
                AddedIFG += "07";
                IFGs--;
            }
            p.setIFG(AddedIFG);
            if (!isAligned(p.getPacket().size()))
            {
                addIFGs(p);
            }

            packets.push_back(p);

            out << p.getPacket() << endl;
        }
        int count = IFGs;
        while (count != 0)
        {
            out << "07";
            count--;
        }
        out<<endl;
    }
    out.close();
}

long long Program::calculateNumberOfBursts()
{
    long long numberOfBursts = 0;

    // Handle bursts if enabled
    if (config.EthBurstSize > 0)
    {
        // Number of Bursts within generation time
        numberOfBursts = config.EthCaptureSizeMs / config.EthBurstPeriodicity_us;
        return numberOfBursts;
    }
    else
    {
        cout << "No bursts are sent in this configuration" << endl;
        return -1;
    }
}
long long Program::handleIFGs()
{
    long long timeOfBurst = (config.EthMaxPacketSize * config.EthBurstSize * 8) / config.EthLineRate;
    long long timePerIFG = (8 / config.EthLineRate) + 1;
    long long totalTimeOfIFGsInPeriod = config.EthBurstPeriodicity_us  - timeOfBurst/1000;
    long long numberOfIFGsInPeriod = totalTimeOfIFGsInPeriod / timePerIFG;
    cout << "Number of IFGs: " << "" << endl;
    return numberOfIFGsInPeriod;
}
bool Program::isAligned(int packetSize)
{
    return packetSize % 4 == 0;
}

void Program::addIFGs(Packet &packet)
{

    int padding = 4 - (packet.getPacket().size() % 4);
    // string packet=packet.getPacket();
    for (int i = 0; i < padding; ++i)
    {
        packet.getPacket() += "07";
    }
}
void Program::dumpPacketsToFile(const std::string &outputFile)
{
    std::ofstream out(outputFile);
    for (Packet &packet : packets)
    {
        out << packet.getPacket() << std::endl;
    }
    out.close();
}

void Program::setConfigurationFile(const std::string &configurationFile)
{

    if (!fileExists(configurationFile))
    {
        throw std::runtime_error("File not found");
    }

    this->configurationFile = configurationFile;
    readConfig();
}

void Program::setOutputFile(const std::string &outputFile)
{
    this->outputFile = outputFile;
}

void Program::setPackets(vector<Packet> &p)
{
    this->packets = p;
}

void Program::readConfig()
{
    config.readConfigurations(configurationFile);
}

bool Program::fileExists(const std::string &fileName)
{
    std::ifstream file(fileName);
    return file.is_open();
}

Program::Program(string configFile, string outputFile)
{
    setConfigurationFile(configFile);
    generatePackets(outputFile);
}