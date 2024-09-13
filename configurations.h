#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H


class configurations
{

public:
    int EthLineRate;
    int EthCaptureSizeMs;
    int EthMinNumOfIFGsPerPacket;
    int EthDestAddress;
    int EthSourceAddress;
    int EthMaxPacketSize;
    int EthBurstSize;
    int EthBurstPeriodicity_us;
    void readConfigurations(string configurationFile);
private:
int getNumberAfterEqual(const std::string& str) ;
void printConfigurations();
};
#endif // CONFIGURATIONS_H
