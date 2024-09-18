#include "parser.h"
#include <fstream>  // Required for file I/O (ifstream, ofstream)


Parser::Parser(std::string configurationFile, std::string outputFile)
{
    this->config.readConfigurations(configurationFile);
    parse(outputFile);
}

void Parser::parse(string input)
{
    int numberOfBursts = config.EthCaptureSizeMs / config.EthBurstPeriodicity_us;
    int numberOfPackets = numberOfBursts * config.EthBurstSize;
    std::ifstream file(input);
    std::ofstream out(input + ".json");
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << input << std::endl;
        return;
    }
    std::string line;
    
    while (std::getline(file, line))
    {
        out<<"{"<<std::endl;
        // FB555555555555 D5
        if (line[0] == 'F' && line[1] == 'B' && line[2] == '5' && line[3] == '5')
        {
            out<<"preamble"<<":"<<"'"<<line.substr(0, 10)<<"'"<<","<<std::endl;
            out<<"SOP : "<<line.substr(10, 2)<<std::endl;
        }
    out<<"},"<<std::endl;
    }
    out.close();
    file.close();
    
}
