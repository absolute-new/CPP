#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main( void )
{
	const int		SIZE = 4;
	Animal*			animals[SIZE];
	for ( int i = 0; i < SIZE / 2; ++i )
		animals[i] = new Dog();
	for ( int j = SIZE / 2; j < SIZE; ++j )
		animals[j] = new Cat();	
	for ( int s = 0; s < SIZE; ++s )
		animals[s]->makeSound();
	for ( int i = 0; i < SIZE; ++i )
		delete animals[i];

	Dog dog1;
	dog1.getBrain().setIdea(0, "EAT");
	Dog dog2(dog1);
	dog2.getBrain().setIdea(0, "SLEEP");
	std::cout << "dog1: " << dog1.getBrain().getIdea(0) << std::endl;
    std::cout << "dog2: " << dog2.getBrain().getIdea(0) << std::endl;

	return ( 0 );
}