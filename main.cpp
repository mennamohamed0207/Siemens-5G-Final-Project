#include <iostream>
#include "Program.h"
using namespace std;
int main()
{
    try
    {
        string configFile="../config.txt";
        string outputFile="output.txt";
        Program program(configFile, configFile);
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}