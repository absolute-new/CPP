#include "Stack2.hpp"

namespace s21
{

template<typename T, typename Cont>
void	Stack<T, Cont>::push(T const& elem)
{
	elemls_.push_back(elem);
}

template<typename T, typename Cont>
void	Stack<T, Cont>::pop()
{
	assert(!elemls_.empty());
	elemls_.pop_back();
}

template<typename T, typename Cont>
T const&	Stack<T, Cont>::top() const
{
	assert(!elemls_.empty());
	return (elemls_.back());
}

template<typename T, typename Cont>
bool	Stack<T, Cont>::empty() const
{
	return (elemls_.empty());
}
	
} // namespace s21
