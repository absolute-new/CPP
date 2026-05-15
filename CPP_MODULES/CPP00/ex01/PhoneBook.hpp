/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   PhoneBook.hpp                                 #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/11 05:42:55 by absolute     ##               #+#        */
/*   Updated: 2026/04/11 05:42:55 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cctype>
# include <unistd.h>

# define maxId 8

class PhoneBook
{
private:
	Contact	contacts[maxId];
	size_t	contactCount;
	int		oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
};

#endif