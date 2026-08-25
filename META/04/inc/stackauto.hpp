#ifndef STACKAUTO_HPP
# define STACKAUTO_HPP

# include <cassert>
# include <array>

namespace s21
{

template<typename T, auto Maxsize>
class Stack
{
public:
	using size_type = decltype(Maxsize);

private:
	std::array<T, Maxsize>	elems_;
	size_type				numElems_;

public:
	Stack();

	void		push(T const& elem);
	void		pop();
	T const&	top() const;
	bool		empty() const;
	size_type	size() const;
};
	
} // namespace s21

# include "stackauto.tpp"

#endif // STACKAUTO_HPP
