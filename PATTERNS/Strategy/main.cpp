#include "Logger.hpp"
#include "FileLogStrategy.hpp"
#include "NetworkLogStrategy.hpp"
#include "ConsoleLogStrategy.hpp"

int	main()
{
	auto Logger = s21::Logger(std::make_unique<s21::FileLogStrategy>("filelog.log"));
	Logger.log("Start");
	Logger.setStrategy(std::make_unique<s21::ConsoleLogStrategy>());
	Logger.log("Write");
	Logger.setStrategy(std::make_unique<s21::NetworkLogStrategy>());
	Logger.log("Finish");
	return (0);
}