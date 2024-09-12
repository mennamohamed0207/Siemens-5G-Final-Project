#include <iostream>
#include <fstream>
#include <string>
#include <configurations.cpp>
using namespace std;

class Program
{
private:
    string configurationFile;
    string outputFile;
    string packets;
    configurations config;

public:
        void readConfig()
    {
        config.readConfigurations(configurationFile);
    }
    void writeFile()
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

    bool fileExists(const std::string &fileName)
    {
        std::ifstream file(fileName);
        return file.is_open();
    }
    void setConfigurationFile(string configurationFile)
    {
        if (fileExists(configurationFile))
        {
            this->configurationFile = configurationFile;
            this->readConfig();
        }
        else
        {
            throw std::runtime_error("File not found");
        }
    }
    void setOutputFile(string outputFile)
    {

        this->outputFile = outputFile;
    }
    void setPackets(string packets)
    {
        this->packets = packets;
    }
};
