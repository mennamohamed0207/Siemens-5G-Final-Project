#include <iostream>
using namespace std;
class Packet
{
private:
    string preamble;
    string SOP;
    string destAddress;
    string srcAddress;
    string ethernetType;
    string payload;
    string CRC;
    string IFG;
public:
    Packet(string destAddress, string srcAddress, string ethernetType, string payload,string SOP="D5",string preamble="FB555555555555");
    Packet();
    string getPreamble();
    string getSOP();
    string getDestAddress();
    string getSrcAddress();
    string getEthernetType();
    string getPayload();
    string getCRC();
    string getIFG();
    string getPacket()  ;
    void setPreamble(string preamble);
    void setSOP(string SOP);
    void setDestAddress(string destAddress);
    void setSrcAddress(string srcAddress);
    void setEthernetType(string ethernetType);
    void setPayload(string payload);
    void setCRC(string CRC);
    void setIFG(string IFG);
};
