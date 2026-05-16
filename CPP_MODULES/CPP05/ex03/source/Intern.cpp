#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm* createPresidentialPardonForm(std::string const& target)
{
	return (new PresidentialPardonForm(target));
}

static AForm* createRobotomyRequestForm(std::string const& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm* createShrubberyCreationForm(std::string const& target)
{
	return (new ShrubberyCreationForm(target));
}

Intern::Intern(void) {}

Intern::Intern(Intern const& other)
{
	(void)other; 
}

Intern::~Intern(void) {}

Intern& Intern::operator=(Intern const& other)
{
	(void)other;
	return (*this);
}

AForm* Intern::makeForm(std::string const& name, std::string const& target) const
{
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[])(std::string const&) = {
		&createShrubberyCreationForm,
		&createRobotomyRequestForm,
		&createPresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formCreators[i](target));
		}
	}
	std::cout << "Intern couldn't create form \"" << name << "\"!" << std::endl;
	return (NULL);
}