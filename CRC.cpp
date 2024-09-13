#include <iostream>
#include <vector>
#include <cstdint>

uint32_t crc32(const std::vector<uint8_t>& data) {
    uint32_t crc = 0xFFFFFFFF;
    const uint32_t polynomial = 0xEDB88320; // Standard CRC32 polynomial

    for (size_t i = 0; i < data.size(); ++i) {
        uint32_t byte = data[i];
        crc ^= byte;
        for (int j = 0; j < 8; ++j) {
            if (crc & 1) {
                crc = (crc >> 1) ^ polynomial;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc ^ 0xFFFFFFFF;
}

int main() {
    // Example packet data
    
    std::vector<uint8_t> packet = {0x01, 0x02, 0x03, 0x04, 0x05}; // Replace with your packet data

    // Calculate CRC32
    uint32_t crc = crc32(packet);

    // Print the CRC in hexadecimal
    std::cout<<std::endl;
    std::cout << "CRC32: " << std::hex << crc << std::endl;

    return 0;
}
