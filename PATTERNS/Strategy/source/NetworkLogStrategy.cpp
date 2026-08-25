#include "NetworkLogStrategy.hpp"
#include <iostream>

namespace s21
{

void	NetworkLogStrategy::write(std::string const& message)
{
	/*
		immotation network log ...
	*/
	std::cout << "[NETWORK] Sending: " << message << std::endl;
}
	
} // namespace s21
