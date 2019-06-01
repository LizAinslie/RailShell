cmake_minimum_required(VERSION 2.8)

# Project's name
project(RailShell)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_SRC ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_INCLUDES ${PROJECT_SOURCE_DIR}/includes)

# The following folder will be included
include_directories("${PROJECT_SRC}" "${PROJECT_INCLUDES}")

# Add the executable
add_executable(rsh ${PROJECT_SRC}/main.cpp)
