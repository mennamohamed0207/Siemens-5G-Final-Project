#include "parser.h"
#include <fstream> // Required for file I/O (ifstream, ofstream)

Parser::Parser(std::string configurationFile, std::string outputFile)
{
    this->config.readConfigurations(configurationFile);
    parse(outputFile);
}

void Parser::parse(string input)
{

    std::ifstream file(input);
    std::ofstream out(input + ".json");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << input << std::endl;
        return;
    }
    std::string line;
    out << "[" << std::endl;
    int i=0;
    while (std::getline(file, line))
    {
        if (line[0] != 'F')
            continue;

        int payloadSize = line.length() - (7 + 1 + 6 + 6 + 2 + 4 + config.EthMinNumOfIFGsPerPacket) * 2;
        if(i!=0)
        out << ",{" << std::endl;
        else 
        out << "{" << std::endl;
        // FB555555555555 D5
        if (line[0] == 'F' && line[1] == 'B' && line[2] == '5' && line[3] == '5')
        {
            out << '"' << "preamble" << '"' << ":" << '"' << line.substr(0, 14) << '"' << "," << std::endl;
            out << '"' << "SOP " << '"' << ":" << '"' << line.substr(14, 2) << '"' << "," << std::endl;
            out << '"' << "Destination Address " << '"' << ":" << '"' << line.substr(16, 12) << '"' << "," << std::endl;
            out << '"' << "Source Address " << '"' << ":" << '"' << line.substr(28, 12) << '"' << "," << std::endl;
            out << '"' << "ethernetType " << '"' << ":" << '"' << line.substr(40, 4) << '"' << "," << std::endl;
            out << '"' << "payload " << '"' << ":" << '"' << line.substr(44, payloadSize) << '"' << "," << std::endl;
            out << '"' << "CRC " << '"' << ":" << '"' << line.substr(44 + payloadSize, 8) << '"' << "," << std::endl;
            out << '"' << "IFG " << '"' << ":" << '"' << line.substr(44 + payloadSize + 8, config.EthMinNumOfIFGsPerPacket) << '"' << std::endl;
        }
        
        out << "}" << std::endl;
        i++;
    }

    out << "]" << std::endl;
    out.close();
    file.close();
}
