#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" )
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat( WrongCat const& other ) : WrongAnimal( other )
{
	std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=( WrongCat const& other )
{
	std::cout << "WrongCat assignment operator called." << std::endl;
	if ( this != &other )
		WrongAnimal::operator=( other );
	return ( *this );
}

void WrongCat::makeSound( void ) const
{
	std::cout << _type << ": * Meow *" << std::endl;
}