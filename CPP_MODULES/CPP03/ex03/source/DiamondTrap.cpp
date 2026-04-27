#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoint	= ScavTrap::_energyPoint;
	_attackDamage	= FragTrap::_attackDamage;
	_name 			= "Default";
	ClapTrap::_name	= _name + "_clap_name";

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string const& name ) : 
	ClapTrap( name + "_clap_name"),
	FragTrap( name ), ScavTrap( name )
{
	_name			= name;
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoint	= ScavTrap::_energyPoint;
	_attackDamage	= FragTrap::_attackDamage;

	std::cout << "DiamondTrap " << _name << " constructor called"
		<< std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const& other ) :
	ClapTrap( other ), FragTrap ( other ), ScavTrap( other ),
	_name( other._name )
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& other )
{
	std::cout << "DiamondTrap copy assignment operator called"
		<< std::endl;

	if ( this != &other )
	{
		ClapTrap::operator=( other );
		_name = other._name;
	}
	return ( *this );
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << _name << ", but my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
}