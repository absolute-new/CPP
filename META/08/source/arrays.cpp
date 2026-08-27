#include "arrays.hpp"

template<typename T1, typename T2, typename T3>
void	foo(int a1[7], int a2[], int (&a3)[42],
	int (&x0)[], T1 x1, T2& x2, T3&& x3)
{
	MyArray::MyClass<decltype(a1)>::print();
	MyArray::MyClass<decltype(a2)>::print();
	MyArray::MyClass<decltype(a3)>::print();
	MyArray::MyClass<decltype(x0)>::print();
	MyArray::MyClass<decltype(x1)>::print();
	MyArray::MyClass<decltype(x2)>::print();
	MyArray::MyClass<decltype(x3)>::print();
}

int main()
{
	int a[42];
	MyArray::MyClass<decltype(a)>::print();
	extern int x[];
	MyArray::MyClass<decltype(x)>::print();
	int x1[] = {0, 8, 15};
	int (&ref)[3] = x1;
	MyArray::MyClass<decltype(ref)>::print();
	foo(a, a, a, x, x, x, x);
	return 0;
}

int x[] = {0, 8, 15};