#include "stackauto.hpp"
#include <iostream>
#include <string>

int	main()
{
	s21::Stack<int, 20u>		int20Stack;
	s21::Stack<std::string, 40>	stringStack;

	int20Stack.push(21);
	std::cout << int20Stack.top() << std::endl;
	auto size1 = int20Stack.size();
	std::cout << size1 << std::endl;
	stringStack.push("Hello, 21");
	std::cout << stringStack.top() << std::endl;
	auto size2 = stringStack.size();
	std::cout << size2 << std::endl;
	if (!std::is_same_v<decltype(size1), decltype(size2)>)
		std::cout << "Non types" << std::endl;
	return (0);
}