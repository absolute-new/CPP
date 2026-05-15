#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain	*_brain;
public:
	Dog( void );
	Dog( Dog const& other );
	~Dog( void );

	Dog& operator=( Dog const& other );
	void makeSound( void ) const;
	Brain& getBrain( void ) const;
};


#endif