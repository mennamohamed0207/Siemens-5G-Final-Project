

#include <string>
#include "configurations.cpp"
#include "Packet.h"

class Program
{
public:
    void setConfigurationFile(const std::string &configurationFile);
    void setOutputFile(const std::string &outputFile);
    void setPackets(Packet*p);
    void readConfig();
    void writeFile();
    bool fileExists(const std::string &fileName);
    Program(string configFile,string outputFile);

private:
    std::string configurationFile;
    std::string outputFile;
    Packet* packets;
    configurations config;
};
