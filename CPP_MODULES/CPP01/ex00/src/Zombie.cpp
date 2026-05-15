/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   Zombie.cpp                                    #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 07:14:01 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 07:14:01 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name_ ) : name(name_) {}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
