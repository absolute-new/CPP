#ifndef STACKNONTYPE_HPP
# define STACKNONTYPE_HPP

# include <cassert>
# include <array>

namespace s21
{

template<typename T, std::size_t Maxsize>
class Stack
{
private:
	std::array<T, Maxsize>	elems_;
	std::size_t				numElems_;
public:
	Stack();
	
	void		push(T const& elem);
	void		pop();
	T const&	top() const;
	bool		empty() const;
	std::size_t	size() const;
};

} // namespace s21

# include "stacknontype.tpp"

#endif // STACKNONTYPE_HPP
