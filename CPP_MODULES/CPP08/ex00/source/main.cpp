#include <iostream>
#include <vector>
#include <list>

# include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vec;
	for (int i = 1; i <= 5; ++i)
		vec.push_back(i * 10);
	try
	{
		std::vector<int>::iterator it = s42::easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;

		*it = 42;
		std::cout << "Change to: " << vec[2] << std::endl;

		s42::easyfind(vec, 100);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	const std::list<int> lst = {1, 2, 3, 4, 5};
	
	try
	{
		std::list<int>::const_iterator cit = s42::easyfind(lst, 5);
		std::cout << "Found in const list: " << *cit << std::endl;

		s42::easyfind(lst, 10);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
