cmake_minimum_required(VERSION 3.5)

project(stacknontypeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stacknontype source/stacknontype.cpp)
target_compile_options(stacknontype PRIVATE -Wall -Werror -Wextra)
target_include_directories(stacknontype PRIVATE include template)

add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})