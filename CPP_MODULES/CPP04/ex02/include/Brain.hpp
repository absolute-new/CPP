#ifndef CLASS_BRAIN_HPP
# define CLASS_BRAIN_HPP

# include <string>

class Brain
{
public:
	static const int nb_ideas = 100;
private:
	std::string	_ideas[nb_ideas];
public:
	Brain( void );
	Brain( Brain const& other );
	~Brain( void );

	Brain& operator=( Brain const& other );
	std::string getIdea( int idx ) const;
	void setIdea( int idx, std::string const& idea );
};

#endif
