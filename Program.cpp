#include "program.h"
#include <iostream>
#include <fstream>
#include "configurations.cpp" // Include the configurations header

void Program::setConfigurationFile(const std::string& configurationFile) {
    // Check if the file exists and throw an exception if it doesn't
    if (!fileExists(configurationFile)) {
        throw std::runtime_error("File not found");
    }

    this->configurationFile = configurationFile;
    readConfig();
}

void Program::setOutputFile(const std::string& outputFile) {
    this->outputFile = outputFile;
}

void Program::setPackets(const std::string& packets) {
    this->packets = packets;
}

void Program::readConfig() {
    // Read the configuration file using the configurations class
    config.readConfigurations(configurationFile);
}

void Program::writeFile() {
    // Open the output file for writing
    std::ofstream file(outputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << outputFile << std::endl;
        return;
    }

    // Write the packets to the file
    file << packets;

    file.close();
}

bool Program::fileExists(const std::string& fileName) {
    std::ifstream file(fileName);
    return file.is_open();
}