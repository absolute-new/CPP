#include <iostream>
#include <atomic>
#include <vector>
#include <thread>

class spinLock
{
private:
	std::atomic_flag	flag;
public:
	spinLock() : flag( ATOMIC_FLAG_INIT ) {}
		
	void	lock()
	{
		while ( flag.test_and_set( std::memory_order_acquire ) )
		{
			/* code */
		}
		
	}

	void	unlock()
	{
		flag.clear( std::memory_order_release );
	}
};

void	test_with_spinlock()
{
	int							count;
	spinLock					mtx;
	std::vector< std::thread >	threads;

	count = 0;
	auto worker = [ & ]()
	{
		for ( int i = 0; i < 10000; ++i )
		{
			mtx.lock();
			count++;
			mtx.unlock();
		}
	};
	for ( int i = 0; i < 10; ++i )
	{
		threads.emplace_back(worker);
	}

	for ( auto& t : threads )
		t.join();
	if ( count == 100000 )
		std::cout << "GOOD" << std::endl;		
}



int	main()
{
	test_with_spinlock();

	return 0;
}