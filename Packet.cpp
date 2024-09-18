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
    this->CRC =  calculateCRC(this->preamble + this->SOP + this->destAddress + this->srcAddress + this->ethernetType + this->payload);
    // std::cout << "CRC32: " << std::hex << this->CRC << std::endl;
}

uint32_t Packet::crc32(const std::vector<uint8_t> &data)
{
    uint32_t crc = 0xFFFFFFFF;
    const uint32_t polynomial = 0xEDB88320; // Standard CRC32 polynomial

    for (size_t i = 0; i < data.size(); ++i)
    {
        uint32_t byte = data[i];
        crc ^= byte;
        for (int j = 0; j < 8; ++j)
        {
            if (crc & 1)
            {
                crc = (crc >> 1) ^ polynomial;
            }
            else
            {
                crc >>= 1;
            }
        }
    }

    return crc ^ 0xFFFFFFFF;
}
string Packet::calculateCRC(string packet) {
    std::vector<uint8_t> bytes(packet.begin(), packet.end());
    uint32_t crcValue = this->crc32(bytes);

    // Convert the 4-byte CRC to a hexadecimal string with 8 digits
    std::stringstream ss;
    ss << std::hex << std::setw(8) << std::setfill('0') << crcValue;
    
    return ss.str();  // Return as hex string
}

Packet::Packet()
{
    this->preamble = "FB555555555555";
    this->SOP = "D5";
    this->CRC = calculateCRC(this->preamble + this->SOP + this->destAddress + this->srcAddress + this->ethernetType + this->payload);
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
