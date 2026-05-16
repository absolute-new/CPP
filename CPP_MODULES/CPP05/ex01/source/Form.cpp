#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : m_name("Basic form"), m_isSigned(false),
	m_gradeRequiredToSign(Bureaucrat::lowestGrade),
	m_gradeRequiredToExecute(Bureaucrat::lowestGrade) {}

Form::Form(std::string const& name, int const gradeToSign, int const gradeToExecute) :
	m_name(name), m_isSigned(false), m_gradeRequiredToSign(gradeToSign),
	m_gradeRequiredToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& other) : m_name(other.m_name), m_isSigned(other.m_isSigned),
	m_gradeRequiredToSign(other.m_gradeRequiredToSign),
	m_gradeRequiredToExecute(other.m_gradeRequiredToExecute) {}

Form::~Form(void) {}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
		m_isSigned = other.m_isSigned;
	return (*this);
}

std::string const& Form::getName(void) const
{
	return (m_name);
}

int Form::getGradeRequiredToSign(void) const
{
	return (m_gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute(void) const
{
	return (m_gradeRequiredToExecute);
}

bool Form::getIsSigned(void) const
{
	return (m_isSigned);
}

void Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > m_gradeRequiredToSign)
		throw GradeTooLowException();
	m_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::ostream& operator<<(std::ostream& os, Form const& form)
{
	os << "Form: " << form.getName() << ", signed: "
		<< (form.getIsSigned() ? "yes" : "no") << ", grade to sign: "
		<< form.getGradeRequiredToSign() << ", grade to execute: "
		<< form.getGradeRequiredToExecute();
	return (os);
}