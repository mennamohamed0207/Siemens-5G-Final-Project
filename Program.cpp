#include <iostream>
#include <fstream>
#include <string>
#include <configurations.h>
using namespace std;
#include <Program.h>

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

void Program::setPackets(const std::string &packets)
{
    this->packets = packets;
}

void Program::readConfig()
{

    this->config.readConfigurations(configurationFile);
}

void Program::writeFile()
{

    std::ofstream file(outputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << outputFile << std::endl;
        return;
    }

    file << packets;

    file.close();
}

bool Program::fileExists(const std::string &fileName)
{
    std::ifstream file(fileName);
    return file.is_open();
}