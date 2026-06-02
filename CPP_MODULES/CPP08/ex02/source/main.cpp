#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	{
		std::cout << "\t\t----- BASIC OPERATIONS -----" << std::endl;

		MutantStack<int>	mstack;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(999);

		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "After pop, size: " << mstack.size() << std::endl;
		std::cout << "New top: " << mstack.top() << std::endl;
	}
	{
		std::cout << "\t\t----- ITERATIONS -----" << std::endl;
		MutantStack<int>	mstack;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(999);

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;		
	}
	{
		std::cout << "\t\t----- REVERSE ITERATIONS -----" << std::endl;
		MutantStack<int>	mstack;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(999);

		MutantStack<int>::iterator end = mstack.end();
		MutantStack<int>::iterator begin = mstack.begin();
		if (begin != end)
		{
			MutantStack<int>::iterator it = mstack.end();
			it--;
			begin--;
			while (it != begin)
			{
				std::cout << *it << " ";
				--it;
			}
			std::cout << std::endl;
		}
	}
	{
		std::cout << "\t\t----- COPY AND ASSIGNMENT -----" << std::endl;
		MutantStack<int>	mstack;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(999);

		MutantStack<int>	copys(mstack);
		MutantStack<int>	assignmentS = mstack;

		std::cout << "Origin stack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Copy stack: ";
		for (MutantStack<int>::iterator it = copys.begin(); it != copys.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Assignment stack: ";
		for (MutantStack<int>::iterator it = assignmentS.begin(); it != assignmentS.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	{
		std::cout << "\t\t----- COMPARE LIST -----" << std::endl;
		
		std::list<int>	lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.push_back(3);
		lst.push_back(37);
		lst.push_back(97);
		lst.push_back(23);
		lst.pop_back();

		MutantStack<int>	mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(37);
		mstack.push(97);


		std::cout << "std::list: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "MutantStack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	return (0);
}
