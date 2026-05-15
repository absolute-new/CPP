#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal
{
protected:
	std::string	_type;
	
public:
	AAnimal( void );
	AAnimal( std::string const &type );
	AAnimal( AAnimal const& other );
	virtual ~AAnimal( void );

	AAnimal& operator=( AAnimal const& other );
	virtual void makeSound( void ) const = 0;
	std::string const& getType( void ) const;
};

#endif
