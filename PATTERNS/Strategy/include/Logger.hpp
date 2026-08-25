#ifndef LOGGER_HPP
# define LOGGER_HPP

# include "LogStrategy.hpp"
# include <memory>
# include <string>

namespace s21
{

class Logger
{
private:
	std::unique_ptr<LogStrategy>	strategy_;

public:
	explicit Logger(std::unique_ptr<LogStrategy> strategy);

	void	setStrategy(std::unique_ptr<LogStrategy> strategy);
	void	log(std::string const& message);
};
	
} // namespace s21

#endif // LOGGER_HPP
