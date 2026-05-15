/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   Contact.hpp                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/11 08:52:07 by absolute     ##               #+#        */
/*   Updated: 2026/04/11 08:52:07 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	login;
	std::string	postalAddress;
	std::string	emailAddress;
	std::string	phoneNumber;
    std::string	birthdayDate;
    std::string	favoriteMeal;
    std::string	underwearColor;
    std::string	darkestSecret;

public:
	Contact();

	void		setFirstName(const std::string& str);
    void		setLastName(const std::string& str);
    void		setNickname(const std::string& str);
    void		setLogin(const std::string& str);
    void		setPostalAddress(const std::string& str);
    void		setEmailAddress(const std::string& str);
    void		setPhoneNumber(const std::string& str);
    void		setBirthdayDate(const std::string& str);
    void		setFavoriteMeal(const std::string& str);
    void		setUnderwearColor(const std::string& str);
    void		setDarkestSecret(const std::string& str);

	std::string	getFirstName() const;
    std::string	getLastName() const;
    std::string	getNickname() const;
    
    void		displaySummary(int index) const;
    void		displayFull() const;
};

#endif //CONTACT_HPP