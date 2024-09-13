

#include <string>
#include "configurations.cpp"
#include "Packet.cpp"
#include <vector>

class Program
{
public:
    void setConfigurationFile(const std::string &configurationFile);
    void setOutputFile(const std::string &outputFile);
    void setPackets(vector<Packet> &p);
    void readConfig();
    // void writeFile();
    bool fileExists(const std::string &fileName);
    Program(string configFile, string outputFile);
    void generatePackets();
    void addIFGs(Packet &packet);
    bool isAligned(int packetSize);
    void dumpPacketsToFile(const std::string &outputFile);


private:
    std::string configurationFile;
    std::string outputFile;
    vector<Packet> packets;
    configurations config;
};
