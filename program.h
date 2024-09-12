

#include <string>

class Program {
public:
    void setConfigurationFile(const std::string& configurationFile);
    void setOutputFile(const std::string& outputFile);
    void setPackets(const std::string& packets);
    void readConfig();
    void writeFile();

private:
    std::string configurationFile;
    std::string outputFile;
    std::string packets;
};

