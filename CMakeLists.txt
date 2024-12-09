cmake_minimum_required(VERSION 3.15)
project(dsa VERSION 0.1.0 LANGUAGES C)

add_executable(dsa main.c)

include(CTest)
enable_testing()

