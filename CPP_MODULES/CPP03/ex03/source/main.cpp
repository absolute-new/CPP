#include "DiamondTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "\n========== TEST 1: Constructors ==========\n" << std::endl;
    
    std::cout << "--- Default constructor ---" << std::endl;
    DiamondTrap defaultTrap;
    
    std::cout << "\n--- Name constructor ---" << std::endl;
    DiamondTrap namedTrap( "Diamond" );
    
    std::cout << "\n--- Copy constructor ---" << std::endl;
    DiamondTrap copyTrap( namedTrap );
    
    std::cout << "\n========== TEST 2: whoAmI() ==========\n" << std::endl;
    
    namedTrap.whoAmI();
    
    std::cout << "\n========== TEST 3: Attack (from ScavTrap) ==========\n" << std::endl;
    
    namedTrap.attack( "Enemy" );
    
    std::cout << "\n========== TEST 4: Inherited methods ==========\n" << std::endl;
    
    namedTrap.takeDamage( 30 );
    namedTrap.beRepaired( 20 );
    
    std::cout << "\n========== TEST 5: High five (from FragTrap) ==========\n" << std::endl;
    
    namedTrap.highFivesGuys();
    
    std::cout << "\n========== TEST 6: Guard gate (from ScavTrap) ==========\n" << std::endl;
    
    namedTrap.guardGate();
    
    std::cout << "\n========== TEST 7: Copy assignment ==========\n" << std::endl;
    
    DiamondTrap trapA( "Alpha" );
    DiamondTrap trapB( "Beta" );
    trapB = trapA;
    trapB.whoAmI();
    
    std::cout << "\n========== TEST 8: Destructors ==========\n" << std::endl;
    
    return ( 0 );
}
