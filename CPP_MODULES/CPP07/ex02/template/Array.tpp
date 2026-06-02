#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <stdexcept>

namespace s42
{
template <typename T>
Array<T>::Array(void) : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]()), size_(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other): array_(NULL), size_(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	if (array_)
		delete[] array_;
	array_ = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] array_;
		size_ = other.size_;
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; ++i)
			array_[i] = other.array_[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= size_)
		throw std::exception();
	return (array_[idx]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= size_)
		throw std::exception();
	return (array_[idx]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (size_);
}
} // namespace s42

#endif
