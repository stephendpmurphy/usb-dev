# Set min req version of Cmake
cmake_minimum_required(VERSION 3.16)

# required for C99 designator aggregate initializer
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(usb-dev)

add_executable(usb-dev main.cpp)
target_link_libraries(usb-dev usb-1.0)