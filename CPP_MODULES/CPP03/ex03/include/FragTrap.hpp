#ifndef CLASS_FRAGTRAP_HPP
# define CLASS_FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string const& name );
	FragTrap( FragTrap const& other );
	~FragTrap( void );

	FragTrap& operator=( FragTrap const& other );

	void	highFivesGuys( void );
};

#endif