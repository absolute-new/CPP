#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hitPoints		= 100;
	_energyPoint	= 50;
	_attackDamage	= 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string const& name ) : ClapTrap( name )
{
	_hitPoints		= 100;
	_energyPoint	= 50;
	_attackDamage	= 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const& other ) : ClapTrap( other )
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const& other )
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if ( this != & other )
	{
		ClapTrap::operator=( other );
	}
	return ( *this );
}

void		ScavTrap::attack( const std::string& target )
{
	if ( _hitPoints == 0 )
	{
		std::cout << "ScavTrap " << _name << " can't attack: no HP!"
			<< std::endl;
		return ;
	}
	if ( _energyPoint == 0 )
	{
		std::cout << "ScavTrap " << _name << " can't attack: no energy!"
			<< std::endl;
		return ;
	}

	--_energyPoint;
	std::cout << "ScavTrap " << _name << " fiercely attacks " << target
		<< ", causing " << _attackDamage << " point of damage!" << std::endl;
}

void		ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!"
		<< std::endl;
}