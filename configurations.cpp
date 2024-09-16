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
string configurations::getAddress(const std::string &str)
{
    size_t pos = str.find('=');
    if (pos != std::string::npos)
    {
        size_t address = str.find('x');
        if (address != std::string::npos)
        {

            std::string numberStr = str.substr(address + 1);
            return numberStr;
        }
        return "";
    }
    else
    {
        std::cerr << "Error: '=' not found in the string!" << std::endl;
        return "";
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
        if (line.find("Eth.LineRate") != std::string::npos)
        {
            EthLineRate = getNumberAfterEqual(line);
        }
        else if (line.find("Eth.CaptureSizeMs") != std::string::npos)
        {
            EthCaptureSizeMs = getNumberAfterEqual(line);
        }
        else if (line.find("Eth.MinNumOfIFGsPerPacket") != std::string::npos)
        {
            EthMinNumOfIFGsPerPacket = getNumberAfterEqual(line);
        }
        else if (line.find("Eth.DestAddress") != std::string::npos)
        {
            EthDestAddress = getAddress(line);
        }
        else if (line.find("Eth.SourceAddress") != std::string::npos)
        {
            EthSourceAddress = getAddress(line);
        }
        else if (line.find("Eth.MaxPacketSize") != std::string::npos)
        {
            EthMaxPacketSize = getNumberAfterEqual(line);
        }
        else if (line.find("Eth.BurstSize") != std::string::npos)
        {
            EthBurstSize = getNumberAfterEqual(line);
        }
        else if (line.find("Eth.BurstPeriodicity_us") != std::string::npos)
        {
            EthBurstPeriodicity_us = getNumberAfterEqual(line);
        }
    }
    printConfigurations();

    file.close();
}