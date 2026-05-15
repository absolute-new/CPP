#ifndef CLASS_CLAPTRAP_HPP
# define CLASS_CLAPTRAP_HPP

# include <string>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
public:
	ClapTrap( void );
	ClapTrap( std::string const& name );
	ClapTrap( const ClapTrap& other );
	~ClapTrap( void );

	ClapTrap& operator=( const ClapTrap& other );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif