

#include <string>
#include "configurations.h"
#include "Packet.h"
#include <vector>
#ifndef PROGRAM_H
#define PROGRAM_H


class Program
{
public:
    Program(string configFile, string outputFile);
    void setConfigurationFile(const std::string &configurationFile);
    void setOutputFile(const std::string &outputFile);
    void setPackets(vector<Packet> &p);
    void readConfig();
    // void writeFile();
    bool fileExists(const std::string &fileName);
    void generatePackets(const std::string &outputFile);
    void addIFGs(Packet &packet);
    bool isAligned(int packetSize);
    void dumpPacketsToFile(const std::string &outputFile);
    configurations getConfig();



private:
    std::string configurationFile;
    std::string outputFile;
    vector<Packet> packets;
    configurations config;
    long long calculateNumberOfBursts();
    long long handleIFGs();
};
#endif // PROGRAM_H
