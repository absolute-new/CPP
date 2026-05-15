#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : m_name("Unknown"), m_grade(lowestGrade) {}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : m_name(name)
{
	if (grade > lowestGrade)
		throw GradeTooLowException();
	if (grade < highestGrade)
		throw GradeTooHighException();
	m_grade = grade;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : 
	m_name(other.m_name), m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
	if (this != &other)
		m_grade = other.m_grade;
	return (*this);
}

std::string const& Bureaucrat::getName(void) const
{
	return (m_name);
}

int Bureaucrat::getGrade(void) const
{
	return (m_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (m_grade - 1 < highestGrade)
		throw GradeTooHighException();
	--m_grade;
}

void Bureaucrat::decrementGrade(void)
{
	if (m_grade + 1 > lowestGrade)
		throw GradeTooLowException();
	++m_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}