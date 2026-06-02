#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <algorithm>
# include <stdexcept>

namespace s42
{
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(),
		container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(),
		container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
}
} // namespace s42

#endif
