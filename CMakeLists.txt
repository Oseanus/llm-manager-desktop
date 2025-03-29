cmake_minimum_required(VERSION 3.30)

set(PRJ LLMManagerDesktop)

# Set the project name
project(${PRJ})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PRJ} ${SOURCES})

# Include directories
include_directories(src)