#include "arrays.hpp"

namespace MyArray
{

template<typename T, std::size_t SZ>
void	MyClass<T[SZ]>::print()
{
	std::cout << "print() для T[" << SZ << "]" << std::endl;
}

template<typename T, std::size_t SZ>
void	MyClass<T(&)[SZ]>::print()
{
	std::cout << "print() для T(&)[" << SZ << "]" << std::endl;
}

template<typename T>
void	MyClass<T[]>::print()
{
	std::cout << "print() для T[]" << std::endl;
}

template<typename T>
void	MyClass<T(&)[]>::print()
{
	std::cout << "print() для T(&)[]" << std::endl;
}

template<typename T>
void	MyClass<T*>::print()
{
	std::cout << "print() для T*" << std::endl;
}

} // namespace MyArray
