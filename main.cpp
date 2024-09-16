#include <iostream>
#include "Program.h"
using namespace std;
int main( int argc, char *argv[] )
{
    try
    { 
        string configFile="../config.txt";
        string outputFile="output.txt";
        // cout<<"Enter path of config file : ";
        // cin>>configFile;
        // cout<<"Enter path of output file : ";
        // cin>>outputFile;
        Program program(configFile, outputFile);
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}