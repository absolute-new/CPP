#include "iter.hpp"
#include <iostream>
#include <string>

int main(void)
{
	{
		std::cout << "-----\tEmpty array test\t-----" << std::endl;
		int intArray[] = {};
		size_t arraySize = 0;

		std::cout << "Empy int array: \t";
		::printArray<int>(intArray, arraySize);
		::iter(intArray, arraySize, ::addOne<int>);

	}
	{
		std::cout << "\t\t------\tINT ARRAY TEST\t-----" << std::endl;
		int array[] = {1, 2, 3, 4, 5};
		size_t arraySize = 5;

		std::cout << "Int array:\t\t\t";
		::printArray(array, arraySize);

		::iter(array, arraySize, ::addOne<int>);
		std::cout << "Int array after increment:\t";
		::printArray(array, arraySize);
	}
	{
		std::cout << "\t\t-----\tDOUBLE ARRAY TEST\t-----" << std::endl;
		double array[] = {1.5, 2.5, 3.5, 4.5, 5.5};
		size_t arraySize = 5;

		std::cout << "Double array:\t\t\t";
		::printArray(array, arraySize);

		::iter(array, arraySize, ::addOne<double>);
		std::cout << "Double array after increment:\t";
		::printArray(array, arraySize);
	}
	{
		std::cout << "\t\t-----\tCHAR ARRAY TEST\t-----" << std::endl;
		char array[] = {'A', 'B', 'C', 'D', 'E'};
		size_t arraySize = 5;

		std::cout << "Char array:\t\t\t";
		::printArray(array, arraySize);

		::iter(array, arraySize, ::addOne<char>);
		std::cout << "Char array after increment:\t";
		::printArray(array, arraySize);
	}
	{
		std::cout << "\t\t-----\tSTRING ARRAY TEST\t-----" << std::endl;
		std::string array[] = {"hello", "world", "test", "42"};
		size_t arraySize = 4;

		std::cout << "String array:\t\t\t";
		::printArray(array, arraySize);

		::iter(array, arraySize, ::upString);
		std::cout << "String array after upcase:\t";
		::printArray(array, arraySize);
	}

	return (0);
}
