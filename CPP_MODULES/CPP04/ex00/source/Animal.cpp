#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type( "Unknown beast" )
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal( std::string const& type ) : _type( type )
{
	std::cout << "Animal param constructor called." << std::endl;
}

Animal::Animal( Animal const& other ) : _type( other._type )
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal& Animal::operator=( Animal const& other )
{
	std::cout << "Animal assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return ( *this );
}

void Animal::makeSound( void ) const
{
	std::cout << _type << ": * Unidentifiable screech *" << std::endl;
}

std::string const& Animal::getType( void ) const
{
	return ( _type );
}