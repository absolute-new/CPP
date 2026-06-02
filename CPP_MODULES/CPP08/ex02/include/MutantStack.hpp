#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	
	iterator		begin(void);
	iterator		end(void);
	const_iterator	cbegin(void) const;
	const_iterator	cend(void) const;
};

# include "../template/MutantStack.tpp"

#endif
