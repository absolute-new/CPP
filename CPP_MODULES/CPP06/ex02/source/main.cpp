#include "BaseUtils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	Base*	p;

	std::srand(std::time(NULL));
	for (int i = 1; i <= 20; ++i)
	{
		std::cout << "Test [" << i << "]:\t";
		p = generate();
		identify(*p);
		identify(p);
		delete p;
	}
	return (0);
}
