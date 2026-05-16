#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("Robotomy request", 72, 45), m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) :
	AForm(other), m_target(other.m_target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return (*this);
}

void RobotomyRequestForm::m_executeAction(void) const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << m_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << m_target << " robotomy failed!" << std::endl;
}