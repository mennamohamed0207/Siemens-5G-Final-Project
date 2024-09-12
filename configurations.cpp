#include<configurations.h>

void configurations::readConfigurations(string configurationFile)
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