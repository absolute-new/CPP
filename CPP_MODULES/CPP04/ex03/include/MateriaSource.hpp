#ifndef CLASS_MATERIA_SOURCE_HPP
# define CLASS_MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static int const	m_maxInventory = 4;
	AMateria*			m_inventory[m_maxInventory];

	void				m_clearInventory( void );
	void				m_initializeEmptyInventory( void );

public:
	MateriaSource( void );
	MateriaSource( MateriaSource const& other );
	~MateriaSource();

	MateriaSource& operator=( MateriaSource const& other );
	
	void learnMateria( AMateria* materia );
	AMateria* createMateria( std::string const& type );
};

#endif
