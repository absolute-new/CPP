#include "Logger.hpp"

namespace s21
{

Logger::Logger(std::unique_ptr<LogStrategy> strategy) : strategy_(std::move(strategy)) {}

void	Logger::setStrategy(std::unique_ptr<LogStrategy> newStratgy)
{
	strategy_ = std::move(newStratgy);
}

void	Logger::log(std::string const& message)
{
	if (strategy_)
		strategy_->write(message);
}
	
} // namespace s21
