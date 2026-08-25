#include "../include/max.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	int			i;
	double		f1;
	double		f2;
	std::string	s1;
	std::string	s2;

	i = 42;
	f1 = 3.14;
	f2 = -6.7;
	s1 = "mathematics";
	s2 = "math";
	std::cout << "max(7, i): " << ::max(7, i) << std::endl;
	std::cout << "max(f1, f2): " << ::max(f1, f2) << std::endl;
	std::cout << "max(s1, s2): " << ::max(s1, s2) << std::endl;
	return (0);
}