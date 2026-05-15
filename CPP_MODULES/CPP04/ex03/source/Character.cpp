#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character( void ) : m_name( "Unnamed" )
{
	m_initializeEmptyInventory();
}

Character::Character( Character const& other ) : m_name( other.m_name )
{
	m_initializeEmptyInventory();
	for ( int i = 0; i < m_maxSlots; ++i )
	{
		if ( other.m_inventory[i] )
			m_inventory[i] = other.m_inventory[i]->clone();
	}

}

Character::Character( std::string const& name ) : m_name( name )
{
	m_initializeEmptyInventory();
}

Character::~Character( void )
{
	m_clearInventory();
}

Character& Character::operator=( Character const& other )
{
	if ( this != &other )
	{
		m_name = other.m_name;
		m_clearInventory();
		for ( int i = 0; i < m_maxSlots; ++i )
		{
			if ( other.m_inventory[i] )
				m_inventory[i] = other.m_inventory[i]->clone();
		}
			
	}
	return ( *this );
}

void Character::m_initializeEmptyInventory( void )
{
	for ( int i = 0; i < m_maxSlots; ++i )
		m_inventory[i] = NULL;
}

void Character::m_clearInventory( void )
{
	for ( int i = 0; i < m_maxSlots; ++i )
	{
		if ( m_inventory[i] != NULL )
		{
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}
	}
}

std::string const& Character::getName( void ) const
{
	return ( m_name );
}

void Character::equip( AMateria* m )
{
	if ( !m )
		return;
	for ( int i = 0; i < m_maxSlots; ++i )
	{
		if ( m_inventory[i] == NULL )
		{
			m_inventory[i] = m;
			return;
		}			
	}
}

void Character::unequip( int idx )
{
	if ( idx < 0 || idx >= m_maxSlots )
		return;
	m_inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if ( idx < 0 || idx >= m_maxSlots )	
		return;
	if ( m_inventory[idx] == NULL )
		return; 
	m_inventory[idx]->use( target );
}