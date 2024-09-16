#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#include "Program.h"

void Program::generatePackets()
{
    int numberOfPackets = calculateNumberOfPackets();
    for (int i = 0; i < numberOfPackets; i++)
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
        
    }
}

int Program::calculateNumberOfPackets()
{
    // int generationTime = config.EthCaptureSizeMs;
    // int lineRate = config.EthLineRate;
    // long long totalDate = (generationTime * lineRate * pow(10, 6));
    // int numberOfPossiblePackets = totalDate / config.EthMaxPacketSize;
    int numberOfPackets =0;

    // Handle bursts if enabled
    if (config.EthBurstSize > 0)
    {
        // Number of Bursts within generation time
        float numberOfBursts = config.EthCaptureSizeMs / config.EthBurstPeriodicity_us;
        numberOfPackets+=(int)numberOfBursts * config.EthBurstSize;

    }
    else
    {
        cout << "No bursts are sent in this configuration" << endl;
        return -1;
    }
    return numberOfPackets;
}
void Program::handleBursts(int numberOfPackets)
{
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

// void Program::writeFile()
// {

//     std::ofstream file(outputFile);
//     if (!file.is_open())
//     {
//         std::cerr << "Error: Could not open the file " << outputFile << std::endl;
//         return;
//     }
//     for (int i = 0; i < packets.size(); i++)
//     {
//         file << packets[i].getPacket() << std::endl;
//     }

//     file.close();
// }

bool Program::fileExists(const std::string &fileName)
{
    std::ifstream file(fileName);
    return file.is_open();
}

Program::Program(string configFile, string outputFile)
{
    setConfigurationFile(configFile);
    generatePackets();
    dumpPacketsToFile(outputFile);
}