#include <iostream>
#include<Program.cpp>
using namespace std;
int main()
{
    Program program;
    try
    {
        // set config file path and then it will be read
        program.setConfigurationFile("config.txt");

        program.setPackets("packets");
        program.setOutputFile("output.txt");
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}