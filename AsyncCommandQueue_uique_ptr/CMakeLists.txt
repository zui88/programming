cmake_minimum_required(VERSION 3.17)
project(AsyncCommandQueue)

set(CMAKE_CXX_STANDARD 20)

add_executable(AsyncCommandQueue main.cpp ascq.hpp util.hpp)