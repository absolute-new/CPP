#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	m_target;
protected:
	void		m_executeAction(void) const;
public:
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& other);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
};

#endif
