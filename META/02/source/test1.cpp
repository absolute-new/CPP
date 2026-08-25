#include "Stack2.hpp"
#include <iostream>
#include <deque>

int	main()
{
	s21::Stack<int>							intStack;
	s21::Stack<double, std::deque<double>>	doubleStack;

	intStack.push(21);
	std::cout << intStack.top() << std::endl;
	intStack.pop();

	doubleStack.push(21.21);
	std::cout << doubleStack.top() << std::endl;
	doubleStack.pop();
	return (0);
}