#include "stacknontype.hpp"
#include <iostream>
#include <string>

int	main()
{
	s21::Stack<int, 20>			int20Stack;
	s21::Stack<int, 40>			int40Stack;
	s21::Stack<std::string, 40>	string40Stack;

	int20Stack.push(21);
	std::cout << int20Stack.top() << std::endl;
	int20Stack.pop();
	int40Stack.push(42);
	std::cout << int40Stack.top() << std::endl;
	int40Stack.pop();
	std::cout << int40Stack.size() << std::endl;
	string40Stack.push("Hello, 21");
	std::cout << string40Stack.top() << std::endl;
	string40Stack.pop();
	return (0);
}