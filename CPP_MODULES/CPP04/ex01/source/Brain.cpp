#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	std::cout << "Brain default contructor called." << std::endl;
}

Brain::Brain( Brain const& other )
{
	std::cout << "Brain copy constructor called." << std::endl;
	for ( int i = 0; i < nb_ideas; ++i )
		_ideas[i] = other._ideas[i];
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=( Brain const& other )
{
	std::cout << "Brain assignmet operator called." << std::endl;
	if ( this != &other )
		for ( int i = 0; i < nb_ideas; ++i )
			_ideas[i] = other._ideas[i];
	return ( *this );
}

std::string Brain::getIdea( int idx ) const
{
	if ( idx >= 0 && idx < nb_ideas )
		return ( _ideas[idx] );
	return "";
}

void Brain::setIdea( int idx, std::string const& idea )
{
	if ( idx >= 0 && idx < nb_ideas )
		_ideas[idx] = idea;
}