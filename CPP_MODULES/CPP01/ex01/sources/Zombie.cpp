#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	std::cout << "A zombie appeared!" << std::endl;
}

Zombie::Zombie( const std::string& name_ ) : name(name_)
{
	std::cout << "A zombie named " << name << " appeared!" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << name << ": deaad" << std::endl;
}

void	Zombie::setName( const std::string& name_ )
{
	name = name_;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}