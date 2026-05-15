#include "HumanA.hpp"

HumanA::HumanA( const std::string& name_, Weapon& weapon_ ) :
	name( name_ ), weapon( weapon_ ) {}

HumanA::~HumanA( void ) {}

void	HumanA::attack() const
{
	std::cout << GREEN << name << RED << " attacks with their " 
		<< weapon.getType() << RESET << std::endl;
}