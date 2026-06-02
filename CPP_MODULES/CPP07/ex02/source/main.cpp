#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		std::cout << "\t\t----- TEST EMPTY SIZE -----" << std::endl;
		s42::Array<int>	empty;
		std::cout << "Empty size: " << empty.size() << std::endl;
	}
	{
		std::cout << "\t\t----- TEST NORMAL SIZE -----" << std::endl;
		s42::Array<int>	arr(5);
		std::cout << "Array size: " << arr.size() << std::endl;
		for (unsigned int i = 0; i < arr.size(); ++i)
		{
			arr[i] = i * 10;
		}
		for (unsigned int i = 0; i < arr.size(); ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		{
			std::cout << "\t\t----- TEST COPY AND [] OPERATORS  -----" << std::endl;
			s42::Array<int>	copy = arr;
			copy[0] = 42;
			std::cout << "Original arr[0]: " << arr[0] << std::endl;
			std::cout << "Copy[0]: " << copy[0] << std::endl;
			try
			{
				arr[10];
			}
			catch(const std::exception& e)
			{
				std::cout << "Out of range!" << std::endl;
			}
		}
	}
	{
		std::cout << "\t\t----- TEST STRING TYPE AND OPERATOR [] -----" << std::endl;
		s42::Array<std::string>	strs(3);
		strs[0] = "Hello";
		strs[1] = "World";
		strs[2] = "42";
		for (unsigned int i = 0; i < strs.size(); ++i)
		std::cout << strs[i] << " ";
		std::cout << std::endl;
	}	
	return (0);	
}
