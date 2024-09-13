#include "configurations.h"

void configurations::printConfigurations()
{
    std::cout << "EthLineRate: " << EthLineRate << std::endl;
    std::cout << "EthCaptureSizeMs: " << EthCaptureSizeMs << std::endl; 
    std::cout << "EthMinNumOfIFGsPerPacket: " << EthMinNumOfIFGsPerPacket << std::endl;
    std::cout << "EthDestAddress: " << EthDestAddress << std::endl;
    std::cout << "EthSourceAddress: " << EthSourceAddress << std::endl;
    std::cout << "EthMaxPacketSize: " << EthMaxPacketSize << std::endl;
    std::cout << "EthBurstSize: " << EthBurstSize << std::endl;
    std::cout << "EthBurstPeriodicity_us: " << EthBurstPeriodicity_us << std::endl;
}
int configurations::getNumberAfterEqual(const std::string &str)
{
    size_t pos = str.find('=');
    if (pos != std::string::npos)
    {
        std::string numberStr = str.substr(pos + 1);
        return std::stoi(numberStr);
    }
    else
    {
        std::cerr << "Error: '=' not found in the string!" << std::endl;
        return -1;
    }
}
void configurations::readConfigurations(string configurationFile)
{
    std::ifstream file(configurationFile);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << configurationFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.find("EthLineRate") != std::string::npos)
        {
            EthLineRate = getNumberAfterEqual(line);
        }
        else if (line.find("EthCaptureSizeMs") != std::string::npos)
        {
            EthCaptureSizeMs = getNumberAfterEqual(line);
        }
        else if (line.find("EthMinNumOfIFGsPerPacket") != std::string::npos)
        {
            EthMinNumOfIFGsPerPacket = getNumberAfterEqual(line);
        }
        else if (line.find("EthDestAddress") != std::string::npos)
        {
            EthDestAddress = getNumberAfterEqual(line);
        }
        else if (line.find("EthSourceAddress") != std::string::npos)
        {
            EthSourceAddress = getNumberAfterEqual(line);
        }
        else if (line.find("EthMaxPacketSize") != std::string::npos)
        {
            EthMaxPacketSize = getNumberAfterEqual(line);
        }
        else if (line.find("EthBurstSize") != std::string::npos)
        {
            EthBurstSize = getNumberAfterEqual(line);
        }
        else if (line.find("EthBurstPeriodicity_us") != std::string::npos)
        {
            EthBurstPeriodicity_us = getNumberAfterEqual(line);
        }
    }
        printConfigurations();

    file.close();
}