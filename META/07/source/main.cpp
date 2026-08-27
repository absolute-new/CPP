#include <iostream>

void	foo()
{
	std::cout << "foo in global scope" << std::endl;
	int x = 0;
	for (int i = 0; i < 1000; ++i)
		x += i;
}

template<typename T>
class Base
{
public:
	void	foo()
	{
		std::cout << "foo in Base class" << std::endl;
		int x = 0;
		for (int i = 0; i < 1000; ++i)
			x += i;
	}

};

template<typename T>
class MyClass : public Base<T>
{
public:
	void	func()
	{
		this->foo();	/*<: not this or Base<T>:: callback global foo*/
	}
};

int main()
{
	MyClass<int>* mClass = new MyClass<int>();
	mClass->func();
	delete mClass;
	return 0;
}
