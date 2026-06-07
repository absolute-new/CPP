#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: need at least one number" << std::endl;
		return (1);
	}
	try
	{
		s42::PmergeMe	pmerge;
		pmerge.parseArguments(argc, argv);
		pmerge.printBefore();
		pmerge.sortAndMeasure();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
