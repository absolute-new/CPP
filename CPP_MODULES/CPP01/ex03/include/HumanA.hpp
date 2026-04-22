#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

# define RED 	"\e[31m"
# define GREEN	"\e[32m"
# define RESET	"\e[0m"

class HumanA
{
private:
	std::string	name;
	Weapon&		weapon;
public:
	HumanA( const std::string& name_, Weapon& weapon_ );
	~HumanA();

	void	attack() const;	
};


#endif