#include "FileLogStrategy.hpp"
#include <fstream>

namespace s21
{

FileLogStrategy::FileLogStrategy(std::string const& file) : filename_(file) {}

void	FileLogStrategy::write(std::string const& message)
{
	std::ofstream	file(filename_, std::ios::app);
	if (file.is_open())
		file << "[FILE] Sending: " << message << std::endl;
}
	
} // namespace s21
