#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string m_target;
protected:
	void		m_executeAction(void) const;
public:
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& other);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(RobotomyRequestForm const& other);
};

#endif
