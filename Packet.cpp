#include "Packet.h"

Packet::Packet(string destAddress, string srcAddress, string ethernetType, string payload, string SOP, string preamble)
{
    this->preamble = preamble;
    this->SOP = SOP;
    this->destAddress = destAddress;
    this->srcAddress = srcAddress;
    this->ethernetType = ethernetType;
    this->payload = payload;
    this->CRC = CRC;
    this->IFG = IFG;
}
Packet::Packet()
{
    this->preamble = "FB555555555555";
    this->SOP = "D5";
}

string Packet::getSOP()
{
    return SOP;
}
string Packet::getDestAddress()
{
    return destAddress;
}
string Packet::getSrcAddress()
{
    return srcAddress;
}
string Packet::getEthernetType()
{
    return ethernetType;
}
string Packet::getPayload()
{
    return payload;
}
string Packet::getCRC()
{
    return CRC;
}
string Packet::getIFG()
{
    return IFG;
}
string Packet::getPacket() 
{
    return preamble + SOP + destAddress + srcAddress + ethernetType + payload + CRC + IFG;
}
void Packet::setPreamble(string preamble)
{
    this->preamble = preamble;
}
void Packet::setSOP(string SOP)
{
    this->SOP = SOP;
}
void Packet::setDestAddress(string destAddress)
{
    this->destAddress = destAddress;
}
void Packet::setSrcAddress(string srcAddress)
{
    this->srcAddress = srcAddress;
}
void Packet::setEthernetType(string ethernetType)
{
    this->ethernetType = ethernetType;
}
void Packet::setPayload(string payload)
{
    this->payload = payload;
}
void Packet::setCRC(string CRC)
{
    this->CRC = CRC;
}
void Packet::setIFG(string IFG)
{
    this->IFG = IFG;
}
