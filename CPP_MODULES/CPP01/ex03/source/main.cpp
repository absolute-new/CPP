#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void )
{
	{
		Weapon club = Weapon( "crude spiked club" );

		HumanA bob( "Bob", club );
		bob.attack();
		club.setType( "some other type of club" );
		bob.attack();
	}

	{
		Weapon club = Weapon( "crude spiked club" );

		HumanB jim( "Jim" );
		jim.setWeapon( club );
		jim.attack();
		club.setType( "some other type of club" );
		jim.attack();
	}
	
	{
		Weapon katana = Weapon( "sharp samurai sword" );

		HumanA alice( "Alice", katana );
		alice.attack();
		katana.setType( "shootgun" );
		alice.attack();
	}

	{
		Weapon katana = Weapon( "sharp samurai sword" );

		HumanB Ivan( "Ivan" );
		Ivan.attack();
		Ivan.setWeapon( katana );
		Ivan.attack();
	}

	return ( 0 );
}