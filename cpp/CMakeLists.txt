cmake_minimum_required(VERSION 3.12) # version can be different

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

project(SS8_CPP) #name of your project

add_subdirectory(../../../googletest/ ./googletest) # add googletest subdirectory


include_directories(~/googletest/googletest/include header/) # this is so we can #include <gtest/gtest.h>

add_executable(CmdLine ./src/main.cpp ./src/ParseCmdLine.cpp ./src/LinuxTerminal.cpp ./src/Terminal.cpp ./src/ChangeDirectory.cpp) # add this executable

add_executable(TestCmdLine test/tests.cpp ./src/ParseCmdLine.cpp ./src/LinuxTerminal.cpp ./src/Terminal.cpp ./src/ChangeDirectory.cpp)

target_link_libraries(TestCmdLine gtest_main)
