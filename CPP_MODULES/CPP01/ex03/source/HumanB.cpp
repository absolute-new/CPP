#include "HumanB.hpp"

HumanB::HumanB( const std::string& name_ ) : name( name_ ), 
	weapon(NULL) {}

HumanB::~HumanB( void ) {}

void	HumanB::attack() const
{
	if ( weapon == NULL )
	{
		std::cout << GREEN << name << " has no weapon to attack!"
			<< RESET << std::endl;
		return ;
	}
	std::cout << GREEN << name << RED << " attacks with their " 
		<< weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon_ )
{
	weapon = &weapon_; 
}