#include "Zombie.hpp"

int main()
{
	int	N;

	N = 5;
	Zombie	*horde = zombieHorde(N, "Walker");
	if ( !horde )
	{
		std::cout << "Error creating horde" << std::endl;
		return 1;
	}
	for ( int i = 0; i < N; ++i )
	{
		horde[i].announce();
	}
	delete [] horde;

	return ( 0 );
}