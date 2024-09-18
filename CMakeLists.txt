# Define the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the C and C++ compilers explicitly
set(CMAKE_C_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "C:\\Users\\dell\\Downloads\\gcc-13.2.0-no-debug\\bin\\g++.exe")

# Define the project name
project(EthernetSimulator)
# Set the C++ standard 
set(CMAKE_CXX_STANDARD 17)

# Ensure consistency of the C++ ABI
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=1")

# Add the executable 
add_executable(EthernetSimulator 
        main.cpp 
        Program.cpp 
        configurations.cpp 
        parser.cpp 
        Packet.cpp
)

# Link the JSON library
target_compile_options(EthernetSimulator PRIVATE -Wall)
