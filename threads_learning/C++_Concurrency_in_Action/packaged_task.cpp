#include <iostream>
#include <future>
#include <thread>
#include <queue>
#include <condition_variable>
#include <memory>

std::condition_variable						cv;
std::queue< std::unique_ptr< std::packaged_task< void() >>>	tasks;
std::mutex													mtx;
bool														shutdown = false; 

void    gui_thread( void )
{
    while ( !shutdown )
    {
        std::unique_ptr< std::packaged_task< void() > >	task_ptr;

        {
            std::unique_lock< std::mutex > lk( mtx );
            cv.wait( lk, [](){ return !tasks.empty() || shutdown; } );
			if ( tasks.empty() )
				continue;
            task_ptr = std::move( tasks.front() );
            tasks.pop();
        }
		if ( task_ptr )
			(*task_ptr)(); // after unlock
    }
} 

template<typename Func>
std::future< void > post_for_gui_thread( Func f )
{
    auto task_ptr = std::make_unique< std::packaged_task< void() > >( f );
    std::future< void >				res = task_ptr->get_future();

    {
		std::lock_guard< std::mutex > lk( mtx );
        tasks.push( std::move( task_ptr ) );
		cv.notify_all();
    }
    return res;
}

int main()
{	
    std::thread	gui( gui_thread );
    auto		f = post_for_gui_thread( []() { std::cout << "Hello, World!" << std::endl; } );
    f.get();
    
	{
		std::lock_guard< std::mutex > lk( mtx );
		shutdown = true;
		cv.notify_all();
	}
	gui.join();

}