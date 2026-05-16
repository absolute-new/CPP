#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
public:
	Intern(void);
	Intern(Intern const& other);
	~Intern(void);

	Intern& operator=(Intern const& other);

	AForm*	makeForm(std::string const& blankName, std::string const& target) const;
};

#endif
