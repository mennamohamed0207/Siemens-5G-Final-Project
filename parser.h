#include "packet.h"
#include "configurations.h"
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#ifndef PARSER_H
#define PARSER_H

class Parser
{
public:
    Parser( configurations configurationFile, std::string outputFile);
    vector<Packet> output;
    string IFGOutput;
    void parse(string inputFile);
    configurations config;

};
#endif 
