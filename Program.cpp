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
};