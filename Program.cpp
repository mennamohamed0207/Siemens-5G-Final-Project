#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Program
{
private:
    string configurationFile;
    string outputFile;
    string packets;

public:
    void readFile()
    {
        std::ifstream file(configurationFile);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open the file " << configurationFile << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

        file.close();
    }

    void writeFile()
    {
        std::ofstream file(outputFile);
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open the file " << outputFile << std::endl;
            return;
        }

        file << packets;

        file.close();
    }

    bool fileExists(const std::string &fileName)
    {
        std::ifstream file(fileName);
        return file.is_open();
    }
    void setConfigurationFile(string configurationFile)
    {
        if (fileExists(configurationFile))
        {
            this->configurationFile = configurationFile;
        }
        else
        {
            throw std::runtime_error("File not found");
        }
    }
    void setOutputFile(string outputFile)
    {

        this->outputFile = outputFile;
    }
    void setPackets(string packets)
    {
        this->packets = packets;
    }
};
int main()
{
    Program program;
    try{
    program.setConfigurationFile("config.txt");
    program.setOutputFile("output.txt");
    program.setPackets("packets.txt");
    program.readFile();
    program.writeFile();
    return 0;

    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}