#ifndef CLASS_CHARACTER_HPP
# define CLASS_CHARACTER_HPP

# include <string> 
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static int const	m_maxSlots = 4;
	std::string			m_name;
	AMateria*			m_inventory[m_maxSlots];

	void				m_initializeEmptyInventory( void );
	void				m_clearInventory( void );
public:
	Character( void );
	Character( Character const& other );
	Character( std::string const& name );
	virtual ~Character( void );

	Character& operator=( Character const& other );

	std::string const&	getName( void ) const;
	void				equip( AMateria* m );
	void				unequip( int idx );
	void				use( int idx, ICharacter& target );
};

#endif
