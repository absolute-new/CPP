#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	AForm("Presidential Pardon", 25, 5), m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) :
	AForm(other), m_target(other.m_target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return (*this);
}

void PresidentialPardonForm::m_executeAction(void) const
{
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}