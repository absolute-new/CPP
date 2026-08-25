cmake_minimum_required(VERSION 3.5)

project(stackautoProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stackauto src/stackauto.cpp)
target_compile_options(stackauto PRIVATE -Wall -Werror -Wextra)
target_include_directories(stackauto PRIVATE inc)

add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})