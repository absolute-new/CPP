#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	std::string const	m_name;
	int					m_grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string const& name, int grade);
	~Bureaucrat(void);
	Bureaucrat(Bureaucrat const& other);

	Bureaucrat& operator=(Bureaucrat const& other);

	std::string const&	getName(void) const;
	int					getGrade(void) const;
	void 				incrementGrade(void);
	void				decrementGrade(void);

	static int const	highestGrade = 1;
	static int const	lowestGrade = 150;

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

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
