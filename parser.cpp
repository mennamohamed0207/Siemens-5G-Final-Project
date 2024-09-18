#include "parser.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

Parser::Parser(string configurationFile, string outputFile)
{
    this->config.readConfigurations(configurationFile);
    parse(outputFile);
}

void Parser::parse(string input)
{
    int numberOfBursts = config.EthCaptureSizeMs / config.EthBurstPeriodicity_us;
    int numberOfPackets = numberOfBursts * config.EthBurstSize;
    std::ifstream file(input);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file " << input << std::endl;
        return;
    }
    std::string line;
    json jsonData;
    while (std::getline(file, line))
    {
        // FB555555555555 D5
        if (line[0] == 'F' && line[1] == 'B' && line[2] == '5' && line[3] == '5')
            jsonData["preamble"] = line.substr(0, 10);
        jsonData["SOP"] = line.substr(10, 2);
    }
    // Step 3: Convert JSON object to string if you want
    std::string jsonString = jsonData.dump(4); // 4-space indentation for pretty-printing
    std::cout << "JSON String:\n"<< jsonString << std::endl;

    // Step 4: Write the JSON data to a file
    std::ofstream jsonFile("output.json");
    if (jsonFile.is_open())
    {
        jsonFile << jsonString;
        jsonFile.close();
        std::cout << "JSON data written to file successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Unable to open file for writing!" << std::endl;
    }
}
