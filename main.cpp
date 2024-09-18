#include <iostream>
#include "Program.h"
#include "parser.h"
using namespace std;
int main()
{
    try
    { 
        string configFile="";
        string outputFile="";
        cout<<"Enter path of config file : ";
        cin>>configFile;
        cout<<"Enter path of output file : ";
        cin>>outputFile;
        Program program(configFile, outputFile);

        Parser parser(program.getConfig(), outputFile);

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}