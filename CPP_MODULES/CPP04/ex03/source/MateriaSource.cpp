#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource( void )
{
	m_initializeEmptyInventory();
}

MateriaSource::MateriaSource( MateriaSource const& other )
{	
	m_initializeEmptyInventory();
	for ( int i = 0; i < m_maxInventory; ++i )
	{
		if ( other.m_inventory[i] )
			m_inventory[i] = other.m_inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource( void )
{	
	m_clearInventory();
}

MateriaSource& MateriaSource::operator=( MateriaSource const& other )
{
	if (this != &other )
	{
		m_clearInventory();
		for ( int i = 0; i < m_maxInventory; ++i )
		{
			if ( other.m_inventory[i] )
				m_inventory[i] = other.m_inventory[i]->clone();
		}
	}
	return ( *this );
}

void MateriaSource::m_clearInventory( void )
{
	for ( int i = 0; i < m_maxInventory; ++i )
	{
		if ( m_inventory[i] != NULL )
		{
			delete m_inventory[i];
			m_inventory[i] = NULL;
		}			
	}
}

AMateria* MateriaSource::createMateria( std::string const& type )
{
	for ( int i = 0; i < m_maxInventory; ++i )
	{
		if ( m_inventory[i] && m_inventory[i]->getType() == type )
			return ( m_inventory[i]->clone() );
	}
	return ( NULL );
}

void MateriaSource::learnMateria( AMateria* materia )
{
	if ( !materia )
		return;
	
	for ( int i = 0; i < m_maxInventory; ++i )
	{
		if ( m_inventory[i] == NULL )
		{
			m_inventory[i] = materia->clone();			
			return;
		}		
	}	
}

void MateriaSource::m_initializeEmptyInventory( void )
{
	for ( int i = 0; i < m_maxInventory; ++i )
		m_inventory[i] = NULL;
}