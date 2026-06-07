#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>
#include <fstream>

void	checkArgs(int, char*[]);

int	main(int argc, char *argv[])
{
	try
	{
		checkArgs(argc, argv);
		s42::BitcoinExchange	btc;
		btc.loadDatabase("data/data.csv");
		btc.processInputFile(argv[1]);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}

void	checkArgs(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
		throw std::runtime_error("Usage: ./btc [file]");
}

