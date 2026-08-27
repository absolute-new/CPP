cmake_minimum_required(VERSION 3.5)
project(testGlobalScope)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(testGlobalScope
	source/main.cpp)
target_compile_options(testGlobalScope PRIVATE
	-Wall -Werror -Wextra)
add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})