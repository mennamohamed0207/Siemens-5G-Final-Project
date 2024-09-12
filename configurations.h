#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
};