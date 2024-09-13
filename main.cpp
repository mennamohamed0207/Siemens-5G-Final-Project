#include <iostream>
#include "Program.cpp"
using namespace std;
int main()
{
    try
    {
        Program program("config.txt", "output.txt");
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}