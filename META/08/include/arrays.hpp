#ifndef ARRAYS_HPP
# define ARRAYS_HPP

# include <iostream>

namespace MyArray
{

template<typename T>
struct MyClass {};

template<typename T, std::size_t SZ>
struct MyClass<T[SZ]>
{
	static void	print();
};

template<typename T, std::size_t SZ>
struct MyClass<T(&)[SZ]>
{
	static void	print();
};

template<typename T>
struct MyClass<T[]>
{
	static void	print();
};

template<typename T>
struct MyClass<T(&)[]>
{
	static void	print();
};

template<typename T>
struct MyClass<T*>
{
	static void	print();
};

} // namespace MyArray

# include "arrays.tpp"

#endif // ARRAYS_HPP
