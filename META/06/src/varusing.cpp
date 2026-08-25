#include <string>
#include <unordered_set>
#include <iostream>

class Customer
{
private:
	std::string	name;

public:
	Customer(std::string const& n) : name(n) {}

	std::string	getName() const
	{
		return (name);
	}
};

struct CustomerEq
{
	bool	operator() (Customer const& c1, Customer const& c2) const
	{
		return (c1.getName() == c2.getName());
	}
};

struct CustomerHash
{
	std::size_t	operator() (Customer const& c) const
	{
		return (std::hash<std::string>() (c.getName()));
	}
};


template<typename... Bases>
struct Overloader : Bases...
{
	using Bases::operator()...;
};

int	main()
{
	using CustomerOp = Overloader<CustomerHash, CustomerEq>;
	std::unordered_set<Customer, CustomerHash, CustomerEq>	coll1;
	std::unordered_set<Customer, CustomerOp, CustomerOp>	coll2;
	Customer c1("Ivan");
	Customer c2("Petr");
	Customer c3("Ivan");
	coll1.insert(c1);
	coll1.insert(c2);
	coll1.insert(c3);
	coll2.insert(c1);
	coll2.insert(c2);
	coll2.insert(c3);
	std::cout << "coll1 size: " << coll1.size() << std::endl;
	std::cout << "coll2 size: " << coll2.size() << std::endl;
	for (auto const& c : coll2) {
		std::cout << c.getName() << std::endl;
	}
	return (0);
}