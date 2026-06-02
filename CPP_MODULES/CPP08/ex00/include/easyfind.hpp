#ifndef EASYFIND_HPP
# define EASYFIND_HPP

namespace s42
{
template<typename T>
typename T::iterator easyfind(T& container, int value);

template<typename T>
typename T::const_iterator easyfind(const T& container, int value);
} // namespace s42

#include "../template/easyfind.tpp"

#endif
