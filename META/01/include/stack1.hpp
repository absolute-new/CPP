#ifndef STACK1_HPP
# define STACK1_HPP

# include <vector>
# include <cassert>

namespace s21
{

template<typename T>
class Stack
{
private:
	std::vector<T>	elems_;

public:
	void		push(T const& elem);
	void		pop();
	T const&	top() const;
	bool		empty() const;
};

} // namespace s21

# include "stack1.tpp"

#endif // STACK1_HPP
