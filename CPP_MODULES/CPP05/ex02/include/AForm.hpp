#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string const	m_name;
	bool				m_isSigned;
	int const			m_gradeRequiredToSign;
	int const			m_gradeRequiredToExecute;
protected:
	virtual void		m_executeAction(void) const = 0;	
public:
	AForm(void);
	AForm(std::string const& name, int const gradeToSign, int const gradeToExecute);
	AForm(AForm const& other);
	virtual ~AForm();

	AForm& operator=(AForm const& other);

	std::string const&	getName(void) const;
	int					getGradeRequiredToSign(void) const;
	int					getGradeRequiredToExecute(void) const;
	bool				getIsSigned(void) const;
	void				beSigned(Bureaucrat const& b);
	void				execute(Bureaucrat const& executor) const;

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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
