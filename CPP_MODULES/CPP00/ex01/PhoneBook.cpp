/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   PhoneBook.cpp                                 #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/11 05:51:54 by absolute     ##               #+#        */
/*   Updated: 2026/04/11 05:51:54 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	std::string	input;
	size_t		index;

	if (contactCount < 8)
	{
		index = contactCount;
	}
	else
	{
		index = oldestIndex;
		oldestIndex = (oldestIndex + 1) % 8;
		std::cout << "PhoneBook is full! Replacing oldest contact." << std::endl;
	}	

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contacts[index].setFirstName(input);
	
	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contacts[index].setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contacts[index].setNickname(input);

	std::cout << "Enter login: ";
	std::getline(std::cin, input);
	contacts[index].setLogin(input);

	std::cout << "Enter postal address: ";
	std::getline(std::cin, input);
	contacts[index].setPostalAddress(input);

	std::cout << "Enter email address: ";
	std::getline(std::cin, input);
	contacts[index].setEmailAddress(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contacts[index].setPhoneNumber(input);

	std::cout << "Enter birthday date: ";
	std::getline(std::cin, input);
	contacts[index].setBirthdayDate(input);

	std::cout << "Enter favorite meal: ";
	std::getline(std::cin, input);
	contacts[index].setFavoriteMeal(input);

	std::cout << "Enter underwear color: ";
	std::getline(std::cin, input);
	contacts[index].setUnderwearColor(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contacts[index].setDarkestSecret(input);

	if (contactCount < 8)
		contactCount++;
	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|" << std::endl;
	std::cout << "----------|----------|----------|----------|" << std::endl;

	for (size_t i = 0; i < contactCount; ++i)
	{
		contacts[i].displaySummary(i + 1);
	}

	std::string answerIdx;
	std::cout << "Enter index to view: ";
	std::getline(std::cin, answerIdx);

	size_t idx = 0;
	for (size_t i = 0; i < answerIdx.length(); ++i)
	{
		if (!std::isdigit(answerIdx[i]))
		{
			std::cout << "Invalid index!" << std::endl;
            return;
		}
		idx = idx * 10 + (answerIdx[i] - '0');
	}

	if (idx < 1 || idx > contactCount)
	{
		std::cout << "Invalid index!" << std::endl;
        return;
	}

	std::system("clear");
	contacts[idx - 1].displayFull();
}