#ifndef LOGSTRATEGY_HPP
# define LOGSTRATEGY_HPP

# include <string>

namespace s21
{

class LogStrategy
{
public:
	virtual ~LogStrategy() = default;
	
	virtual void	write(std::string const& message) = 0;
};
	
} // namespace s21


#endif // LOGSTRATEGY_HPP
