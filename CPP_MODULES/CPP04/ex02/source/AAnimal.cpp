#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal( void ) : _type( "Unknown beast" )
{
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal( std::string const& type ) : _type( type )
{
	std::cout << "AAnimal param constructor called." << std::endl;
}

AAnimal::AAnimal( AAnimal const& other ) : _type( other._type )
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal destructor called." << std::endl;
}

AAnimal& AAnimal::operator=( AAnimal const& other )
{
	std::cout << "AAnimal assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return ( *this );
}

// void Animal::makeSound( void ) const
// {
// 	std::cout << _type << ": * Unidentifiable screech *" << std::endl;
// }

std::string const& AAnimal::getType( void ) const
{
	return ( _type );
}