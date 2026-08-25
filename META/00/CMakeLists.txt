cmake_minimum_required(VERSION 3.20)

project(MaxTemplateExample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(max_example ./source/max.cpp)

target_include_directories(max_example PRIVATE include)