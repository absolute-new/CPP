cmake_minimum_required(VERSION 3.5)

project(varusingProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(varusing src/varusing.cpp)
target_compile_options(varusing PRIVATE -Wall -Werror -Wextra)
target_include_directories(varusing PRIVATE inc)

add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})