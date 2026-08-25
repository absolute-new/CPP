#include "ConsoleLogStrategy.hpp"
#include <iostream>

namespace s21
{

void	ConsoleLogStrategy::write(std::string const& message)
{
	std::cout << "[CONSOLE] Sending: " << message << std::endl;
}
	
} // namespace s21
