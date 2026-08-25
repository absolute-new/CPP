#include "stacknontype.hpp"

namespace s21
{

template<typename T, std::size_t Maxsize>
Stack<T, Maxsize>::Stack() : numElems_(0) {}

template<typename T, std::size_t Maxsize>
void	Stack<T, Maxsize>::push(T const& elem)
{
	assert(numElems_ < Maxsize);
	elems_[numElems_] = elem;
	++numElems_;
}

template<typename T, std::size_t Maxsize>
void	Stack<T, Maxsize>::pop()
{
	assert(!empty());
	--numElems_;
}

template<typename T, std::size_t Maxsize>
T const&	Stack<T, Maxsize>::top() const
{
	assert(!empty());
	return (elems_[numElems_ - 1]);
}

template<typename T, std::size_t Maxsize>
bool	Stack<T, Maxsize>::empty() const
{
	return (numElems_ == 0);
}

template<typename T, std::size_t Maxsize>
std::size_t	Stack<T, Maxsize>::size() const
{
	return (numElems_);
}

} // namespace s21
