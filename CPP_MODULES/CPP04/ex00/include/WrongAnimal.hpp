#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	std::string	_type;
public:
	WrongAnimal( void );
	WrongAnimal( std::string const& type );
	WrongAnimal( WrongAnimal const& other );
	~WrongAnimal( void );

	WrongAnimal& operator=( WrongAnimal const& other );
	void makeSound( void ) const;
	std::string const& getType( void ) const;
};


#endif