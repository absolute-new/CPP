#include <iostream>
#include <future>
#include <thread> 

int main()
{
    std::promise<int>	promise;
    std::future<int>	future = promise.get_future();
    std::thread			sender([&promise]()
	{
        std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
        promise.set_value( 42 );
    });   

    auto res = future.get();
	std::cout << "result = " << res << std::endl;
	sender.join();

	return 0;
}
