#ifndef CLASS_DIAMONDTRAP_HPP
# define CLASS_DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap( void );
	DiamondTrap( std::string const& name );
	DiamondTrap( DiamondTrap const& other );
	~DiamondTrap( void );

	DiamondTrap& operator=( DiamondTrap const& other );

	using	ScavTrap::attack;
	void	whoAmI( void );
};

#endif