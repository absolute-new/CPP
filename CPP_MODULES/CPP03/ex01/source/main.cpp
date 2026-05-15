#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "\n========== TEST 1: Constructors ==========\n" << std::endl;
    
    std::cout << "--- Creating ScavTrap with default constructor ---" << std::endl;
    ScavTrap defaultTrap;
    
    std::cout << "\n--- Creating ScavTrap with name constructor ---" << std::endl;
    ScavTrap namedTrap( "Guardian" );
    
    std::cout << "\n--- Creating ScavTrap with copy constructor ---" << std::endl;
    ScavTrap copyTrap( namedTrap );
    
    std::cout << "\n========== TEST 2: Attack method ==========\n" << std::endl;
    
    namedTrap.attack( "Enemy1" );
    namedTrap.attack( "Enemy2" );
    namedTrap.attack( "Enemy3" );
    
    std::cout << "\n========== TEST 3: Damage and Repair ==========\n" << std::endl;
    
    namedTrap.takeDamage( 30 );
    namedTrap.takeDamage( 50 );
    namedTrap.takeDamage( 100 );
    
    namedTrap.beRepaired( 20 );
    
    std::cout << "\n========== TEST 4: Guard Gate ==========\n" << std::endl;
    
    namedTrap.guardGate();
    
    std::cout << "\n========== TEST 5: No energy ==========\n" << std::endl;
    
    ScavTrap weakTrap( "WeakBot" );
    for ( int i = 0; i < 50; i++ )
        weakTrap.attack("Target");
    
    weakTrap.beRepaired(10);

    std::cout << "\n========== TEST 6: Copy assignment ==========\n" << std::endl;
    
    ScavTrap trapA( "Alpha" );
    ScavTrap trapB( "Beta" );
    
    trapB = trapA;
    trapB.attack( "Enemy" );
    
    std::cout << "\n========== TEST 7: Destructors ==========\n" << std::endl;
    
    return ( 0 );
}
