#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
protected:
	std::string	_type;
	
public:
	Animal( void );
	Animal( std::string const &type );
	Animal( Animal const& other );
	virtual ~Animal( void );

	Animal& operator=( Animal const& other );
	virtual void makeSound( void ) const;
	std::string const& getType( void ) const;
};

#endif
