#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("Shrubbery Creation", 145, 137), m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) :
	AForm(other), m_target(other.m_target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return (*this);
}

void ShrubberyCreationForm::m_executeAction(void) const
{
	std::string filename = m_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
		file.close();
	}
}