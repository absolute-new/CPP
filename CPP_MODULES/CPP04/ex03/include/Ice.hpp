#ifndef CLASS_ICE_HPP
# define CLASS_ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice( void );
	Ice( Ice const& other );
	~Ice( void );

	Ice& operator=( Ice const& other );
	AMateria* clone( void ) const;
	void use( ICharacter& target );
};

#endif
