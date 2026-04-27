#ifndef CLASS_SCAVTRAP_HPP
# define CLASS_SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string const& name );
	ScavTrap( ScavTrap const& other );
	~ScavTrap( void );

	ScavTrap& operator=( ScavTrap const& other );

	void	attack( const std::string& target );
	void	guardGate( void );
};

#endif