#ifndef FILELOGSTRATEGY_HPP
# define FILELOGSTRATEGY_HPP

# include "LogStrategy.hpp"
# include <string>

namespace s21
{

class FileLogStrategy : public LogStrategy
{
private:
	std::string	filename_;
public:
	explicit FileLogStrategy(std::string const& file);
	
	void	write(std::string const& message) override;
};
	
} // namespace s21



#endif // FILELOGSTRATEGY_HPP