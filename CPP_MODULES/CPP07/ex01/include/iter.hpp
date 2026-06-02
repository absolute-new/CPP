#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T, typename Func>
void	iter(T* array, int size, Func function)
{
	for (int i = 0; i < size; ++i)
		function(array[i]);
}

template<typename T>
void	printArray(T* array, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		std::cout << "[" << array[i] << "] ";
	std::cout << std::endl;
}

template<typename T>
void	addOne(T& num)
{
	num += 1;
}

void	upString(std::string& str)
{
	for (std::string::iterator it = str.begin();
		it != str.end(); ++it)
		*it = std::toupper(*it);
}

#endif
