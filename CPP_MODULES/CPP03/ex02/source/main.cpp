#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "\n========== TEST 1: Constructors ==========\n" << std::endl;
    
    std::cout << "--- Default constructor ---" << std::endl;
    FragTrap defaultTrap;
    
    std::cout << "\n--- Name constructor ---" << std::endl;
    FragTrap namedTrap( "Fraggy" );
    
    std::cout << "\n--- Copy constructor ---" << std::endl;
    FragTrap copyTrap( namedTrap );
    
    std::cout << "\n========== TEST 2: High Five ==========\n" << std::endl;
    
    namedTrap.highFivesGuys();
    
    std::cout << "\n========== TEST 3: Inherited methods ==========\n" << std::endl;
    
    namedTrap.attack( "Enemy1" );
    namedTrap.attack( "Enemy2" );
    namedTrap.takeDamage( 50 );
    namedTrap.beRepaired( 30 );
    namedTrap.takeDamage( 100 );
    namedTrap.beRepaired( 20 );
    
    std::cout << "\n========== TEST 4: No energy ==========\n" << std::endl;
    
    FragTrap weakTrap("WeakBot");
    for ( int i = 0; i < 101; i++ )
        weakTrap.attack( "Target" );
    weakTrap.beRepaired( 10 );
    
    std::cout << "\n========== TEST 5: Copy assignment ==========\n" << std::endl;
    
    FragTrap trapA( "Alpha" );
    FragTrap trapB( "Beta" );
    
    trapB = trapA;
    trapB.highFivesGuys();
    trapB.attack( "Enemy" );
    
    std::cout << "\n========== TEST 6: Destructors ==========\n" << std::endl;
    
    return ( 0 );
}
