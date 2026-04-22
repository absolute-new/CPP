/* ************************************************************************** */
/*                                                                            */
/*                                                    ########        #####   */
/*   main.cpp                                       #+#    #+#       #+#:#    */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <absolute>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2025/09/23 11:49:42 by absolute     ##               #+#        */
/*   Updated: 2025/09/23 11:49:44 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {

	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Weclome to your PhoneBook!" << std::endl;
	sleep(3);
	std::system("clear");
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD" || command == "add") {
			phoneBook.addContact();
		} 
		else if (command == "SEARCH" || command == "search") 
		{
			std::system("clear");
			phoneBook.searchContact();
		} 
		else if (command == "EXIT" || command == "exit") 
		{
			std::system("clear");
			std::cout << "Goodbye! :)" << std::endl;
			break;
		} 
		else 
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}

	return 0;
}
