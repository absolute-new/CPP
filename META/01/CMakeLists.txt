cmake_minimum_required(VERSION 3.5)

project(stackTemplateProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(stack_template INTERFACE)

target_include_directories(stack_template INTERFACE include template)
target_compile_options(stack_template INTERFACE -Wall -Werror -Wextra)

add_executable(check_stack tests/test1.cpp)
target_link_libraries(check_stack PRIVATE stack_template)

add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})