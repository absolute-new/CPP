#include "stackauto.hpp"

namespace s21
{

template<typename T, auto Maxsize>
Stack<T, Maxsize>::Stack() : numElems_(0) {}

template<typename T, auto Maxsize>
void	Stack<T, Maxsize>::push(T const& elem)
{
	assert(numElems_ < Maxsize);
	elems_[numElems_] = elem;
	numElems_++;
}

template<typename T, auto Maxsize>
void	Stack<T, Maxsize>::pop()
{
	assert(!empty());
	--numElems_;
}

template<typename T, auto Maxsize>
T const&	Stack<T, Maxsize>::top() const
{
	assert(!empty());
	return (elems_[numElems_ - 1]);
}

template<typename T, auto Maxsize>
bool	Stack<T, Maxsize>::empty() const
{
	return (numElems_ == 0);
}

template<typename T, auto Maxsize>
typename Stack<T, Maxsize>::size_type	Stack<T, Maxsize>::size() const
{
	return (numElems_);
}
	
} // namespace s21
