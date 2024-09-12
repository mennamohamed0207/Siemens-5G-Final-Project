

#include <string>
#include <configurations.h>

class Program
{
public:
    void setConfigurationFile(const std::string &configurationFile);
    void setOutputFile(const std::string &outputFile);
    void setPackets(const std::string &packets);
    void readConfig();
    void writeFile();
    bool fileExists(const std::string &fileName);

private:
    std::string configurationFile;
    std::string outputFile;
    std::string packets;
    configurations config;
};
