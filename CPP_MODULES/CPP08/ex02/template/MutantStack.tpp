template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin(void) const
{
	return (this->c.cbegin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend(void) const
{
	return (this->c.cend());
}