#ifndef CLASS_CURE_HPP
# define CLASS_CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure( void );
	Cure( Cure const& other );
	~Cure( void );

	Cure& operator=( Cure const& other );
	AMateria* clone( void ) const;
	void use( ICharacter& target );
};

#endif
