#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints		= 100;
	_energyPoint	= 100;
	_attackDamage	= 30;
}

FragTrap::FragTrap( std::string const& name ) : ClapTrap( name )
{
	std::cout << "FragTrap " << _name << " constructor called"
		<< std::endl;
	_hitPoints		= 100;
	_energyPoint	= 100;
	_attackDamage	= 30;
}

FragTrap::FragTrap( FragTrap const& other ) : ClapTrap ( other )
{
	
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=( FragTrap const& other )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if ( this != &other )
		ClapTrap::operator=( other );
	return ( *this );
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << _name << " says: HIGH FIVE GUYS!"
		<< std::endl;
}