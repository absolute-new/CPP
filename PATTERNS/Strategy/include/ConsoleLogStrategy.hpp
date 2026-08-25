#ifndef CONSOLELOGSTRATEGY_HPP
# define CONSOLELOGSTRATEGY_HPP

# include "LogStrategy.hpp"
# include <string>

namespace s21
{

class ConsoleLogStrategy : public LogStrategy
{
public:
	void	write(std::string const& message) override;
};
	
} // namespace s21



#endif // CONSOLELOGSTRATEGY_HPP