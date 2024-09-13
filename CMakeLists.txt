cmake_minimum_required(VERSION 3.0.0)   # Selects the minimum version of CMake required to run this file
project(SiemensFinalProject VERSION 0.1.0)          # Here we select the project name and version

# Here we select C++17 with all the standards required and all compiler-specific extensions disabled
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# A variable with all our source files that are common between executable targets (examples)
set(COMMON_SOURCES
        configurations.h
        configurations.cpp
        Packet.h
        Packet.cpp
        Program.h
        Program.cpp

)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)

add_executable(SiemensFinalProject main.cpp  ${COMMON_SOURCES} )
target_link_libraries(SiemensFinalProject)