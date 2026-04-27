#include "ClapTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "\n=== TEST 1: Construction ===\n" << std::endl;
    
    ClapTrap defaultTrap;
    ClapTrap namedTrap( "BOT-42" );
    ClapTrap copyTrap( namedTrap );
    
    std::cout << "\n=== TEST 2: Attack ===\n" << std::endl;
    
    namedTrap.attack( "Enemy" );
    namedTrap.attack( "Enemy" );
    namedTrap.attack( "Enemy" ); 
    
    std::cout << "\n=== TEST 3: Damage and Repair ===\n" << std::endl;
    
    namedTrap.takeDamage( 5 );
    namedTrap.takeDamage( 5 );
    namedTrap.takeDamage( 5 );     

    namedTrap.beRepaired( 10 );
    
    std::cout << "\n=== TEST 4: No energy ===\n" << std::endl;
    
    ClapTrap weakTrap( "Weak" );
    for (int i = 0; i < 12; i++)
        weakTrap.attack( "Target" );
    
    weakTrap.beRepaired(5);
    
    std::cout << "\n=== TEST 5: Copy assignment ===\n" << std::endl;
    
    ClapTrap trapA( "Alpha" );
    ClapTrap trapB( "Beta" );
    trapB = trapA;
    trapB.attack( "Target" );
    
    std::cout << "\n=== Destructors ===\n" << std::endl;
    
    return ( 0 );
}
