#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

namespace s42
{
template <typename T>
class Array
{
private:
	T*				array_;
	unsigned int	size_;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array<T>& other);
	~Array(void);

	Array&		operator=(const Array<T>& other);
	T&			operator[](unsigned int idx);
	const T&	operator[](unsigned int idx) const;

	unsigned int size(void) const;
};

} // namespace s42

#include "../template/Array.tpp"

#endif
