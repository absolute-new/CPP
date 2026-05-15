/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   Zombie.hpp                                   #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 07:04:24 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 07:04:24 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:
	std::string	name;

public:
	Zombie( std::string name_ );
	~Zombie();
	void	announce( void );
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif