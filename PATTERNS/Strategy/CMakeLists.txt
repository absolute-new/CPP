cmake_minimum_required(VERSION 3.5)

project(StrategyPatternProjetc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
	main.cpp
	source/ConsoleLogStrategy.cpp
	source/FileLogStrategy.cpp
	source/NetworkLogStrategy.cpp
	source/Logger.cpp)

add_executable(StrategyPattern ${SOURCES})
target_compile_options(StrategyPattern PRIVATE -Wall -Werror -Wextra)
target_include_directories(StrategyPattern PRIVATE include)

add_custom_target(fclean
	COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR})