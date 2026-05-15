#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

# define RED 	"\e[31m"
# define GREEN	"\e[32m"
# define RESET	"\e[0m"

class HumanB
{
private:
	std::string	name;
	Weapon*		weapon;	
public:
	HumanB( const std::string& name_ );
	~HumanB();

	void	attack() const;
	void	setWeapon( Weapon& weapon_ );
};


#endif