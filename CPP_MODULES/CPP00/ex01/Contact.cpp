/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   Contact.cpp                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/11 09:40:01 by absolute     ##               #+#        */
/*   Updated: 2026/04/11 09:40:01 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void  Contact::setFirstName(const std::string &str) { firstName = str; }
void  Contact::setLastName(const std::string &str) { lastName = str; }
void  Contact::setNickname(const std::string &str) { nickName = str; }
void  Contact::setLogin(const std::string &str) { login = str; }
void  Contact::setPostalAddress(const std::string &str) { postalAddress = str; }
void  Contact::setEmailAddress(const std::string &str) { emailAddress = str; }
void  Contact::setPhoneNumber(const std::string &str) { phoneNumber = str; }
void  Contact::setBirthdayDate(const std::string &str) { birthdayDate = str; }
void  Contact::setFavoriteMeal(const std::string &str) { favoriteMeal = str; }
void  Contact::setUnderwearColor(const std::string &str)
{
  underwearColor = str;
}
void  Contact::setDarkestSecret(const std::string &str) { darkestSecret = str; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickName; }

void  Contact::displaySummary(int index) const
{
  std::string fName = firstName;
  std::string lName = lastName;
  std::string nname = nickName;

  if (fName.length() > 10) 
    fName = fName.substr(0, 9) + ".";
  if (lName.length() > 10) 
    lName = lName.substr(0, 9) + ".";
  if (nname.length() > 10) 
    nname = nname.substr(0, 9) + ".";

  std::cout << std::setw(10) << std::right << index << "|";
  std::cout << std::setw(10) << std::right << fName << "|";
  std::cout << std::setw(10) << std::right << lName << "|";
  std::cout << std::setw(10) << std::right << nname << "|" << std::endl;
}

void  Contact::displayFull() const
{
  std::cout << "First name: " << firstName << std::endl;
  std::cout << "Last name: " << lastName << std::endl;
  std::cout << "Nickname: " << nickName << std::endl;
  std::cout << "Login: " << login << std::endl;
  std::cout << "Postal address: " << postalAddress << std::endl;
  std::cout << "Email address: " << emailAddress << std::endl;
  std::cout << "Phone number: " << phoneNumber << std::endl;
  std::cout << "Birthday date: " << birthdayDate << std::endl;
  std::cout << "Favorite meal: " << favoriteMeal << std::endl;
  std::cout << "Underwear color: " << underwearColor << std::endl;
  std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
