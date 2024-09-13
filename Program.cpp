#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Program.h"

void Program::generatePackets()
{
    int generationTime = config.EthCaptureSizeMs;
    int burstSize = config.EthBurstSize;
    int burstPeriodicity = config.EthBurstPeriodicity_us;
    for (int i = 0; i < generationTime; i += burstPeriodicity)
    {
        for (int j = 0; j < burstSize; j++)
        {
            string destAddress = to_string(config.EthDestAddress);
            string srcAddress = to_string(config.EthSourceAddress);
            string ethernetType = "0800";
            string payload = "0000";
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