# Define the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the C and C++ compilers explicitly
set(CMAKE_C_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\gcc.exe")

# Specify the compiler 
set(CMAKE_CXX_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\g++.exe")
# Define the project name
project(EthernetSimulator)


# FetchContent is used to automatically download and configure the library
include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2 # Or the latest version
)

FetchContent_MakeAvailable(json)

# Set the C++ standard 
set(CMAKE_CXX_STANDARD 17)

# Add the executable 
add_executable(EthernetSimulator 
        main.cpp 
        Program.cpp 
        configurations.cpp 
        Packet.cpp
        Packet.h
        Program.h
        configurations.h
        parser.h
        parser.cpp
        
)


target_compile_options(EthernetSimulator PRIVATE -Wall)
target_link_libraries(EthernetSimulator PRIVATE nlohmann_json::nlohmann_json)

