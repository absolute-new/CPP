# include "stack1.hpp"

namespace s21
{

template<typename T>
void	Stack<T>::push(T const& elem)
{
	elems_.push_back(elem);
}

template<typename T>
void	Stack<T>::pop()
{
	assert(!elems_.empty());
	elems_.pop_back();
}

template<typename T>
T const&	Stack<T>::top() const
{
	assert(!elems_.empty());
	return (elems_.back());
}

template<typename T>
bool	Stack<T>::empty() const
{
	return (elems_.empty());
}

} // namespace s21
