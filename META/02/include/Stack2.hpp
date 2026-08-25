#ifndef STACK2_HPP
# define STACK2_HPP

# include <vector>
# include <cassert>

namespace s21
{

template<typename T, typename Cont = std::vector<T>>
class Stack
{
private:
	Cont	elemls_;

public:
	void		push(T const& elem);
	void		pop();
	T const&	top() const;
	bool		empty() const;

};
	
} // namespace s21

# include "Stack2.tpp"

#endif // STACK2_HPP
