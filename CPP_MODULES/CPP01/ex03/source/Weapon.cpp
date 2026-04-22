#include "Weapon.hpp"

Weapon::Weapon( const std::string& type_ ) : type(type_) {}

Weapon::~Weapon( void ) {}

const std::string&	Weapon::getType() const
{
	return type;
}

void	Weapon::setType( const std::string& newType )
{
	type = newType;
}