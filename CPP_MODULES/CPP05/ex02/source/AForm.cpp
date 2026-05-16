#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : m_name("Basic form"), m_isSigned(false),
	m_gradeRequiredToSign(Bureaucrat::lowestGrade),
	m_gradeRequiredToExecute(Bureaucrat::lowestGrade) {}

AForm::AForm(std::string const& name, int const gradeToSign, int const gradeToExecute) :
	m_name(name), m_isSigned(false), m_gradeRequiredToSign(gradeToSign),
	m_gradeRequiredToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& other) : m_name(other.m_name), m_isSigned(other.m_isSigned),
	m_gradeRequiredToSign(other.m_gradeRequiredToSign),
	m_gradeRequiredToExecute(other.m_gradeRequiredToExecute) {}

AForm::~AForm(void) {}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
		m_isSigned = other.m_isSigned;
	return (*this);
}

std::string const& AForm::getName(void) const
{
	return (m_name);
}

int AForm::getGradeRequiredToSign(void) const
{
	return (m_gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute(void) const
{
	return (m_gradeRequiredToExecute);
}

bool AForm::getIsSigned(void) const
{
	return (m_isSigned);
}

void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > m_gradeRequiredToSign)
		throw GradeTooLowException();
	m_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream& os, AForm const& form)
{
	os << "AForm: " << form.getName() << ", signed: "
		<< (form.getIsSigned() ? "yes" : "no") << ", grade to sign: "
		<< form.getGradeRequiredToSign() << ", grade to execute: "
		<< form.getGradeRequiredToExecute();
	return (os);
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!m_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > m_gradeRequiredToExecute)
		throw GradeTooLowException();
	m_executeAction();
}