#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

namespace s42
{
class BitcoinExchange
{
private:
	std::map<std::string, float>	data_;
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();


	void		loadDatabase(const std::string& filename = "data.csv");
	void		processInputFile(const std::string& filename);
	float		getRate(const std::string& date) const;	
private:
	void		addEntry_(const std::string& date, float price);
	void		parseDatabaseLine_(const std::string& line);
	void		parseInputLine_(const std::string& line);
	bool		isValidDate_(const std::string& date) const;
	bool		isValidValue_(const std::string& value, float& outValue) const;
	float		getCloseRate_(const std::string& date) const;
	std::pair<std::string, std::string> splitLine_(const std::string&line,
		char delimeter) const;
	std::string	trim_(const std::string& str) const;
};

} // namespace s42

#endif
