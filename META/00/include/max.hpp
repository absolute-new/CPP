#ifndef MAX_HPP
# define MAX_HPP

template<typename T>
T	max(T a, T b)
{
	return (a < b ? b : a);
}

#endif // MAX_HPP
