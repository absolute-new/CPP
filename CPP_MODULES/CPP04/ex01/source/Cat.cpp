#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal( "Cat" ), _brain( new Brain() )
{
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat( Cat const& other ) : Animal( other ), _brain( new Brain( *other._brain ) )
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

Cat& Cat::operator=( Cat const& other )
{
	std::cout << "Cat assignment operator called." << std::endl;
	if ( this != &other )
	{
		Animal::operator=( other );
		*_brain = *other._brain;
	}
	return ( *this );
}

void Cat::makeSound( void ) const
{
	std::cout << _type << ": * Meow *" << std::endl;
}