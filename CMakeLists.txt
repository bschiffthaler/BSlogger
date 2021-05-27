cmake_minimum_required(VERSION 3.10)

# set the project name
project(BSLogger-Tests)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined -Wall -Wextra ${CMAKE_CXX_FLAGS}")

# add the executable
add_executable(bslogger-examples src/bslogger_examples.cpp)
