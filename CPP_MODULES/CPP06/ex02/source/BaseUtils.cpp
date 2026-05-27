#include "BaseUtils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	int	rnd = std::rand() % 3;

	switch (rnd)
	{
	case 0:
		std::cout << "Generated: A" << std::endl;
		return (new A);
		break;
	case 1:
		std::cout << "Generated: B" << std::endl;
		return (new B);
		break;
	case 2:
		std::cout << "Generated: C" << std::endl;
		return (new C);
		break;
	default:
		break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Identified as reference: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception&)	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception&) {}
	std::cout << "Unknown" << std::endl;
}