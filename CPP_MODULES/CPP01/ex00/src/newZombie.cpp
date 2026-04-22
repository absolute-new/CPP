/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   newZombie.cpp                                 #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 07:12:57 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 07:12:57 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie*	zombie = new Zombie( name );
	return (zombie);
}
