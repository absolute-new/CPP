/*  
    std::async
*/

#include <future>
#include <string>
#include <iostream>
#include <thread>

struct	s_foo
{
	int	getNum() const
	{
		return num;
	}

    void    foo( int num_, std::string const& str )
    {
        num = num_;
        std::cout << "foo in thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "num = " << num << ", str = " << str << std::endl;
    }

private:
    int	num;
}; 

struct	s_fnc
{
    s_fnc() : num(0.0) {}
    s_fnc( double d ) : num(d) {}  
	double	getNum() const
	{
		return num;
	} 

    double  operator()(double x)
    {
		std::cout << "s_fnc in thread: " << std::this_thread::get_id() << std::endl;
		num += x;
        return num + x;
    }

private:
    double	num;
}; 

struct	X
{
	int	value = 0;
}; 

void	baz( X& x )
{
    x.value = 42;
	std::cout << "baz in thread: " << std::this_thread::get_id() << std::endl;
    std::cout << "baz:value = " << x.value << std::endl;
}
 

int main()
{
    s_foo	obj;
    s_fnc	funct;
    X		x;   

	std::cout << "main in thread: " << std::this_thread::get_id() << std::endl << std::endl;

    /* wait async thread(std::launch::async) link method*/
    auto futureLink = std::async(std::launch::async, &s_foo::foo, &obj, 42, "Hello!");
    futureLink.get();
	std::cout << "After foo value = " << obj.getNum() << std::endl;
	std::cout << std::endl; 

    /* wait async thread(std::launch::async) copy method*/
    std::future<void> futureCpy = std::async(std::launch::async, &s_foo::foo, obj, 12, "Hello!");
    futureCpy.get();
	std::cout << "After foo value = " << obj.getNum() << std::endl;
	std::cout << std::endl;  

    /* wait async thread(std::launch::async) ref method*/
    auto futureRef = std::async(std::launch::async, &s_foo::foo, std::ref(obj), 21, "Hello!");
    futureRef.get();
	std::cout << "After foo value = " << obj.getNum() << std::endl;
    std::cout << std::endl;

    std::future<double> futureD1 = std::async(std::launch::deferred, s_fnc(3.0), 5.0);
    double res1 = futureD1.get();
    std::cout << "future result with copy: " << res1 << std::endl; 
	std::cout << "After result value = " << funct.getNum() << std::endl;  
	std::cout << std::endl;

    std::future<double> futureD2 = std::async(std::ref(funct), 5.0);
    double res2 = futureD2.get();
    std::cout << "future result with ref: " << res2 << std::endl;   
	std::cout << "After result value = " << funct.getNum() << std::endl; 
	std::cout << std::endl;

    auto bazRef = std::async(baz, std::ref(x));
    bazRef.get();
    std::cout << "After baz value = " << x.value << std::endl;
	std::cout << std::endl;

	return 0;
}