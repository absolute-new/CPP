#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <sstream>

/*   constructor and destructor   */
s42::RPN::RPN(void) : stack_() {}

s42::RPN::~RPN(void) {}

/*	public methods	*/
int		s42::RPN::calculate(const std::string& expression)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (isNumber(token))
			stack_.push(token[0] - '0');
		else if (isOperator(token))
			performOperator(token);
		else
			throw std::runtime_error("Error: invalid token");
	}
	if (stack_.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return (stack_.top());
}

/*	private methods	*/
bool	s42::RPN::isNumber(const std::string& token) const
{
	return (token.length() == 1 && std::isdigit(token[0]));
}

bool	s42::RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*"
		|| token == "/");
}

void	s42::RPN::performOperator(const std::string& op)
{
	if (stack_.size() < 2)
		throw std::runtime_error("Error: not enough operands");
	int	b = stack_.top();
	stack_.pop();
	int	a = stack_.top();
	stack_.pop();
	int	result = 0;

	if (op == "+")
		result = a + b;
	else if (op == "-")
		result = a - b;
	else if (op == "*")
		result = a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by zero");
		result = a / b;
	}
	stack_.push(result);
}
