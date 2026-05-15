#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test from subject ===" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		delete ice;
		
		AMateria* cure = new Cure();
		src->learnMateria(cure);
		delete cure;
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	
	std::cout << "\n=== Deep copy test ===" << std::endl;
	{
		Character* original = new Character("Original");
		original->equip(new Ice());
		original->equip(new Cure());
		
		Character* copy = new Character(*original);
		
		std::cout << "Original name: " << original->getName() << std::endl;
		std::cout << "Copy name: " << copy->getName() << std::endl;
		
		original->use(0, *copy);
		copy->use(1, *original);
		
		delete original;
		delete copy;
	}
	
	std::cout << "\n=== Full inventory test ===" << std::endl;
	{
		Character* hero = new Character("Hero");

		hero->equip(new Ice());
		hero->equip(new Cure());
		hero->equip(new Ice());
		hero->equip(new Cure());

		AMateria* extra = new Ice();
		hero->equip(extra);
		delete extra;

		Character* dummy = new Character("Dummy");

		hero->use(0, *dummy);
		hero->use(1, *dummy);
		hero->use(2, *dummy);
		hero->use(3, *dummy);
		hero->use(4, *dummy);
		hero->use(-1, *dummy);

		delete dummy;
		delete hero;
	}
	
	std::cout << "\n=== Unequip test ===" << std::endl;
	{
		Character* hero = new Character("Hero");
		
		AMateria* ice = new Ice();
		hero->equip(ice);
		hero->use(0, *hero);
		hero->unequip(0);
		hero->use(0, *hero);
		
		delete ice;
		delete hero;
	}
	
	std::cout << "\n=== Unknown type test ===" << std::endl;
	{
		MateriaSource* src = new MateriaSource();
		
		AMateria* tmp = src->createMateria("ice");  // NULL — не знает
		if (tmp == NULL)
			std::cout << "Unknown type returned NULL" << std::endl;
		
		delete src;
	}
	
	std::cout << "\n=== Assignment operator test ===" << std::endl;
	{
		Character* a = new Character("Alice");
		a->equip(new Ice());
		
		Character* b = new Character("Bob");
		b->equip(new Cure());
		
		*b = *a;
		
		a->use(0, *b);
		b->use(0, *a);
		
		delete a;
		delete b;
	}
	
	return (0);
}