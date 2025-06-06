cmake_minimum_required(VERSION 3.30)

set(PRJ LLMManagerDesktop)

# Set the project name
project(${PRJ})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find the Qt6 package
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Include Qt standard project setup
qt_standard_project_setup()

# Add the executable
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.h")

add_executable(${PRJ} ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(${PRJ} PRIVATE Qt6::Core Qt6::Widgets curl)

# Include directories
include_directories(src)
include_directories(${Qt6Widgets_INCLUDE_DIRS})