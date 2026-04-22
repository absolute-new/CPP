#include <iostream>
#include <atomic>
#include <thread>

std::atomic< bool >	flag{false};

void	workerFlag()
{
	while ( !flag.load() )
	{		
		std::cout << "workFlag" << std::endl; 
	}
	std::cout << "stopped Flag" << std::endl;
}

void	workerCompare()
{
	bool	expect;

	expect = false;
	std::this_thread::sleep_for( std::chrono::milliseconds( 500 ) );
	while ( flag.compare_exchange_weak( expect, true, std::memory_order_acq_rel ) && expect );
	{
		std::cout << "workCompare" << std::endl;
	}
	std::cout << "stopped Compare" << std::endl;
}

int	main()
{
	std::thread	t1( workerFlag );
	std::thread	t2( workerCompare );
	std::this_thread::sleep_for(std::chrono::seconds(1));
	

	t1.join();
	t2.join();

	return 0;
}