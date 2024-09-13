# Define the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the C and C++ compilers explicitly
set(CMAKE_C_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\gcc.exe")

# Specify the compiler (optional, if needed to specify explicitly)
set(CMAKE_CXX_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\g++.exe")
# Define the project name
project(EthernetSimulator)

# Set the C++ standard to C++11 or C++17
set(CMAKE_CXX_STANDARD 17)

# Add the executable (this assumes main.cpp is the entry point)
add_executable(EthernetSimulator 
        main.cpp 
        Program.cpp 
        configurations.cpp 
        Packet.cpp
        Packet.h
        Program.h
        configurations.h
        
)

# Add any additional compiler flags if needed (optional)
# Example: Enable all warnings
target_compile_options(EthernetSimulator PRIVATE -Wall)
