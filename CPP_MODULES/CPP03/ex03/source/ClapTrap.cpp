#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) : _name( "default" ), _hitPoints( 10 ),
	_energyPoint( 10 ), _attackDamage( 0 )
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string const& name ) : _name( name ), _hitPoints( 10 ),
	_energyPoint( 10 ), _attackDamage( 0 )
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) : _name( other._name ),
	_hitPoints( other._hitPoints ), _energyPoint( other._energyPoint ),
	_attackDamage( other._attackDamage )
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if ( this != &other )
	{
		_name			= other._name;
		_hitPoints		= other._hitPoints;
		_energyPoint	= other._energyPoint;
		_attackDamage	= other._attackDamage;
	}
	return ( *this );
}

void	ClapTrap::attack( const std::string& target )
{
	if ( _hitPoints == 0 )
	{
		std::cout << "ClapTrap " << _name << " can't attack: no HP"
			<< std::endl;
		return ;
	}
	if ( _energyPoint == 0 )
	{
		std::cout << "ClapTrap " << _name << " can't attack: no energy"
			<< std::endl;
		return ;
	}

	--_energyPoint;

	std::cout << "ClapTrap " << _name << " attacks " << target <<
		", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( _hitPoints == 0 )
	{
		std::cout << "ClapTrap " << _name << " is already dead!"
			<< std::endl;
		return ;
	}
	if ( amount >= _hitPoints )
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( _hitPoints == 0 )
	{
		std::cout << "ClapTrap " << _name << " can't repair "
			<< "- no hit points left!" << std::endl;
		return ;
	}
	if ( _energyPoint == 0 )
	{
		std::cout << "ClapTrap " << _name << " can't repair "
			<< "- no energy points left!" << std::endl;
		return ;
	}

	_energyPoint--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, gaining "
		<< amount << " hit points! Hit points now: " << _hitPoints
		<< std::endl;
}