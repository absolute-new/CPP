#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const	m_name;
	bool				m_isSigned;
	int const			m_gradeRequiredToSign;
	int const			m_gradeRequiredToExecute;
public:
	Form(void);
	Form(std::string const& name, int const gradeToSign, int const gradeToExecute);
	Form(Form const& other);
	~Form();

	Form& operator=(Form const& other);

	std::string const&	getName(void) const;
	int					getGradeRequiredToSign(void) const;
	int					getGradeRequiredToExecute(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(Bureaucrat const& b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
