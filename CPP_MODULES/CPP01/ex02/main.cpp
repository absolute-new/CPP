#include <iostream>
#include <string>

int main()
{
	std::string const	str = "HI THIS IS BRAIN";
	std::string const*	ptr_str = &str;
	std::string const&	ref_str = str;

	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << ptr_str << std::endl;
	std::cout << "The memory address held by stringREF: " << &ref_str << std::endl;

	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *ptr_str << std::endl;
	std::cout << "The value pointed to by stringREF: " << ref_str << std::endl;

	return (0);
}
