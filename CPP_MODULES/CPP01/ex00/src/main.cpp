/* ************************************************************************** */
/*                                                                            */
/*                                                   ########        #####    */
/*   main.cpp                                      #+#    #+#       #+#:#     */
/*                                                       #:#      ##  #:#     */
/*   By: absolute <napoleof>                          #+#      +#    #:#      */
/*                                                 #+#              #+#       */
/*   Created: 2026/04/15 07:25:01 by absolute     ##               #+#        */
/*   Updated: 2026/04/15 07:25:01 by absolute     ########        ###         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombie1 = newZombie("heap");
	zombie1->announce();
	randomChump("stack");
	delete zombie1;

	return 0;
}
