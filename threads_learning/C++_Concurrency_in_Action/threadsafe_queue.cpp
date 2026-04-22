#include <condition_variable>
#include <mutex>
#include <queue>
#include <memory> 

template< typename T >
class threadsafe_queue
{
private:
    std::queue< T >			dataQ;
    std::condition_variable	data_cond;
    mutable std::mutex		mtx;   

public:

    threadsafe_queue() = default;
    threadsafe_queue( threadsafe_queue&& other )
    {
        std::lock_guard< std::mutex > lk( other.mtx );
        dataQ = std::move( other.dataQ );
    }

    threadsafe_queue( const threadsafe_queue&) = delete;
    threadsafe_queue& operator=(const threadsafe_queue& ) = delete;   

    void	push(T newValue )
    {
        {
            std::lock_guard< std::mutex > lg( mtx );
            dataQ.push( std::move( newValue ) );
        }
        data_cond.notify_one();
    }   

    bool    try_pop( T& value )
    {
        std::lock_guard< std::mutex > lg( mtx );
        if ( dataQ.empty() )
            return false;
        value = std::move( dataQ.front() );
        dataQ.pop();
        return true;
    }

    std::shared_ptr< T > try_pop()
    {
        std::lock_guard< std::mutex > lg( mtx );
        if ( dataQ.empty() )
            return std::shared_ptr< T >();
        std::shared_ptr< T > res( std::make_shared< T >( std::move( dataQ.front() ) ) );
        dataQ.pop();
        return res;
    }  

    void    wait_and_pop( T& value )
    {
        std::unique_lock< std::mutex > ul( mtx );
        data_cond.wait( ul, [this]{ return !dataQ.empty(); } );
        value = std::move( dataQ.front() );
        dataQ.pop();
    }

    std::shared_ptr< T > wait_and_pop()
    {
        std::unique_lock< std::mutex > ul( mtx );
        data_cond.wait( ul, [this]{ return !dataQ.empty(); } );
        std::shared_ptr< T > res( std::make_shared< T >( std::move( dataQ.front() ) ) );
        dataQ.pop();
        return res;
    }

    bool    empty() const
    {
        std::lock_guard< std::mutex > lg( mtx );
        return dataQ.empty();
    }
};

 
