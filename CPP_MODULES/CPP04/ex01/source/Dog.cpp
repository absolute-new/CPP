#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal( "Dog" ), _brain( new Brain() )
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( Dog const& other ) : Animal( other ), _brain( new Brain( *other._brain ) )
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

Dog& Dog::operator=( Dog const& other )
{
	std::cout << "Dog assignment operator called." << std::endl;
	if ( this != &other )
	{
		Animal::operator=( other );
		*_brain = *other._brain;
	}
	return ( *this );
}

void Dog::makeSound( void ) const
{
	std::cout << _type << ": * Bark *" << std::endl;
}

Brain& Dog::getBrain( void ) const
{
	return ( *_brain );
}