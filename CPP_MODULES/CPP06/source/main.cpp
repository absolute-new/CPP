#include "Converter.hpp"
#include <iostream>


int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert_scalar <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			<< std::endl;
		return (1);
	}
	
	try
	{
		std::cout << "-----Converting [" << argv[1] << "]"
			<< "-----" << std::endl;
		Converter convert(argv[1]);
		std::cout << convert << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
		

	return (0);
}