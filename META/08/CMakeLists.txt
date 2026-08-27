cmake_minimum_required(VERSION 3.5)
project(testMyArray)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(testMyArray
	source/arrays.cpp)
target_compile_options(testMyArray PRIVATE
	-Wall -Wextra -Werror)
target_include_directories(testMyArray PRIVATE include)
add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})