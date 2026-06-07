#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>
#include <iostream>

/* constructors and destructor */
s42::BitcoinExchange::BitcoinExchange(void) : data_() {}

s42::BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

s42::BitcoinExchange& s42::BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		this->data_ = other.data_;
	return (*this);
}

s42::BitcoinExchange::~BitcoinExchange(void) {}

/* private methods */
void	s42::BitcoinExchange::parseDatabaseLine_(const std::string& line)
{
	size_t	commaPos = line.find(',');
	if (commaPos == std::string::npos)
	{
		std::cerr << "Error: invalid line in database: "
			<< line << std::endl;
		return ;
	}
	std::string	date = line.substr(0, commaPos);
	std::string	price = line.substr(commaPos + 1);
	date = trim_(date);
	price = trim_(price);
	if (!isValidDate_(date))
	{
		std::cerr << "Error: invalid date in database: "
			<< date << std::endl;
		return ;
	}
	float	priceValue;
	if (!isValidValue_(price, priceValue) || priceValue < 0)
	{
		std::cerr << "Error: invalid price in database: "
			<< price << std::endl;
		return ;
	}
	addEntry_(date, priceValue);
}

bool	s42::BitcoinExchange::isValidDate_(const std::string& date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(date[i]))
			return (false);
	}
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool	s42::BitcoinExchange::isValidValue_(const std::string& value,
	float& outValue) const
{
	char	*endPos;
	outValue = std::strtof(value.c_str(), &endPos);
	if (*endPos != '\0')
		return (false);
	return (true);
}

void	s42::BitcoinExchange::addEntry_(const std::string& date, float price)
{
	data_[date] = price;
}

void	s42::BitcoinExchange::parseInputLine_(const std::string& line)
{
	size_t	pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::string	date = line.substr(0, pipePos);
	std::string	value = line.substr(pipePos + 1);
	date = trim_(date);
	value = trim_(value);
	if (!isValidDate_(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	float	valueNum;
	if (!isValidValue_(value, valueNum))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (valueNum < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (valueNum > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}    
	float rate = getCloseRate_(date);
	std::cout << date << " => " << valueNum << " = " << valueNum * rate << std::endl;
}

float	s42::BitcoinExchange::getCloseRate_(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = data_.lower_bound(date);
	if (it == data_.end())
	{
		if (data_.empty())
			return (0.0f);
		return ((--data_.end())->second);
	}
	if (it->first == date)
		return (it->second);
	if (it == data_.begin())
		return (0.0f);
	--it;
	return (it->second);
}

std::pair<std::string, std::string>	s42::BitcoinExchange::splitLine_(const
	std::string& line, char delimeter) const
{
	size_t	pos = line.find(delimeter);
	if (pos == std::string::npos)
		return (std::make_pair("", ""));
	std::string	first = line.substr(0, pos);
	std::string second = line.substr(pos + 1);
	return (std::make_pair(trim_(first), trim_(second)));
}

std::string s42::BitcoinExchange::trim_(const std::string& str) const
{
	size_t	start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return "";
	size_t	end = str.find_last_not_of(" \t\n\r\f\v");

	return (str.substr(start, end - start + 1));
}

/* public methods */
void	s42::BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream	fs(filename.c_str());
	if (!fs.is_open())
		throw std::runtime_error("Could not open file: " + filename);
	std::string		line;
	std::getline(fs, line);

	while (std::getline(fs, line))
	{
		if (!line.empty())
			parseDatabaseLine_(line);
	}	
}

void	s42::BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream	fs(filename.c_str());
	if (!fs.is_open())
		throw std::runtime_error("Could not open input file " + filename);
	std::string		line;
	std::getline(fs, line);

	while (std::getline(fs, line))
	{
		if (!line.empty())
			parseInputLine_(line);
	}	
}

float	s42::BitcoinExchange::getRate(const std::string& date) const
{
	return (getCloseRate_(date));
}