#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria( void ) : m_type( "Unknown" ) {}

AMateria::AMateria( std::string const& type ) : m_type( type ) {}

AMateria::AMateria( AMateria const& other ) : m_type( other.m_type ) {}

AMateria::~AMateria( void ) {}

AMateria& AMateria::operator=( AMateria const& other )
{	
	if ( this != &other )
		m_type = other.m_type;
	return ( *this );
}

std::string const& AMateria::getType( void ) const
{
	return ( m_type );
}

void AMateria::use( ICharacter& target )
{
	(void)target;
}