#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal( "Dog" )
{
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog( Dog const& other ) : Animal( other )
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called." << std::endl;
}

Dog& Dog::operator=( Dog const& other )
{
	std::cout << "Dog assignment operator called." << std::endl;
	if ( this != &other )
		Animal::operator=( other );
	return ( *this );
}

void Dog::makeSound( void ) const
{
	std::cout << _type << ": * Bark *" << std::endl;
}