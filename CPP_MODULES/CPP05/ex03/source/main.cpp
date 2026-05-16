#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    
    std::cout << "---- TEST INTERN CREATES VALID FORMS ----" << std::endl;
    
    AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* robot = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Ford");
    
    std::cout << *shrub << std::endl;
    std::cout << *robot << std::endl;
    std::cout << *pardon << std::endl;
    
    std::cout << "\n---- TEST INTERN INVALID FORM ----" << std::endl;
    AForm* invalid = someRandomIntern.makeForm("coffee request", "mug");
    (void)invalid;
	
    std::cout << "\n---- TEST SIGN AND EXECUTE ----" << std::endl;
    boss.signForm(*shrub);
    boss.executeForm(*shrub);
    
    boss.signForm(*robot);
    boss.executeForm(*robot);
    
    boss.signForm(*pardon);
    boss.executeForm(*pardon);
    
    delete shrub;
    delete robot;
    delete pardon;
    
    return (0);
}