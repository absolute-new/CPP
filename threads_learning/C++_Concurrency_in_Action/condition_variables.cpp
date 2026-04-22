#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue> 

std::condition_variable	cv;
std::mutex				mtx;
std::queue<int>			q; 

void    producer()
{    
    for (int i = 0; i < 5; ++i)
    {
		std::this_thread::sleep_for(std::chrono::milliseconds( 5000 ));
		{
			std::lock_guard<std::mutex> lk( mtx );		
        	q.push( i );
			std::cout << "producer push: " << i << std::endl;
        	cv.notify_one();
     	 // cv.notify_all() //
		}
	}
}

void    consumer()
{
    while ( true )
    {
        std::unique_lock< std::mutex > lk( mtx );
        cv.wait( lk, [](){ return !q.empty(); } );
        int value = q.front();
        q.pop();
		std::cout << "consumer get: " << value << std::endl;
        lk.unlock();   

        if ( value == 4 )
            break;
    }
} 

int main()
{
    std::thread	t1( producer );
    std::thread	t2( consumer );   

    t1.join();
    t2.join();

	return 0;
}