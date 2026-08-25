#ifndef NETWORKLOGSTRATEGY_HPP
# define NETWORKLOGSTRATEGY_HPP

# include "LogStrategy.hpp"
# include <string>

namespace s21
{

class NetworkLogStrategy : public LogStrategy
{
public:
	void	write(std::string const& message) override;
};
	
} // namespace s21

#endif // NETWORKLOGSTRATEGY_HPP
