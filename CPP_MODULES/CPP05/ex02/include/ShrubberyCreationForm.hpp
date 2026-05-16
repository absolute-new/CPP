#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	m_target;
protected:
	void		m_executeAction(void) const;
public:
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& other);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
};

#endif
