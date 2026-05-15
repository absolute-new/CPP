#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : _type( "Unknown animal" )
{
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string const& type ) : _type( type )
{
	std::cout << "WrongAnimal param constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& other ) :_type( other._type )
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& other )
{
	std::cout << "WrongAnimal assignment operator called." << std::endl;
	if ( this != &other )
		_type = other._type;
	return ( *this );
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << _type << ": * Unidentifiable screech *" << std::endl;
}

std::string const& WrongAnimal::getType( void ) const
{
	return ( _type );
}