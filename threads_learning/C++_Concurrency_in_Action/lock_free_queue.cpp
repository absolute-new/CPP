#include <atomic>
#include <memory>

template< typename T >
class LockFreeQueue
{
private:
	struct CountedNodePtr
	{
		int		external_count;
		Node*	ptr;
	};
	struct NodeCounter
	{
		unsigned int	internal_count : 30;
		unsigned int	external_counters : 2;
	};
	
	struct Node
	{
		std::atomic< T* >				data;
		std::atomic< NodeCounter >		count;
		std::atomic< CountedNodePtr >	next;
	};
	std::atomic< CountedNodePtr >		head;
	std::atomic< CountedNodePtr >		tail;
	
	static void	increase_external_count( std::atomic< CountedNodePtr >& counter ,
		CountedNodePtr& old_counter )
	{
		CountedNodePtr	new_counter;
		do
		{
			new_counter = old_counter;
			++new_counter.external_count;
		} while ( !counter.compare_exchange_strong( old_counter, new_counter,
				std::memory_order_acquire, std::memory_order_relaxed ) );
		
		old_counter.external_count = new_counter.external_count;		
	}

	static void	free_external_counter( CountedNodePtr& old_node_ptr )
	{
		Node* const	ptr 			= old_node_ptr.ptr;
		int const	count_increase	= old_node_ptr.external_count - 2;

		NodeCounter	old_counter		= ptr->count.load( std::memory_order_relaxed );
		NodeCounter	new_counter;

		do
		{
			new_counter = old_counter;
			--new_counter.external_counters;
			new_counter.internal_count += count_increase;
		} while ( !ptr->count.compare_exchange_strong( old_counter, new_counter,
				std::memory_order_acquire, std::memory_order_relaxed ) );

		if ( !new_counter.internal_count && !new_counter.external_counters )
			delete ptr;		
	}

	static void	release_ref( Node* ptr )
	{
		NodeCounter	old_counter = ptr->count.load( std::memory_order_relaxed );
		NodeCounter	new_counter;

		do
		{
			new_counter = old_counter;
			--new_counter.internal_count;
		} while ( !ptr->count.compare_exchange_strong( old_counter, new_counter,
				std::memory_order_acquire, std::memory_order_relaxed ) );

		if ( !new_counter.internal_count && !new_counter.external_counters )
			delete ptr;		
	}

	void		set_new_tail( CountedNodePtr& old_tail, CountedNodePtr const& new_tail )
	{
		Node* const	current_tail_ptr = old_tail.ptr;

		while ( !tail.compare_exchange_weak( old_tail, new_tail ) && 
				old_tail.ptr == current_tail_ptr );

		if ( old_tail.ptr == current_tail_ptr )
			free_external_counter( old_tail );
		else
			release_ref( current_tail_ptr );		
	}
	
public:
	LockFreeQueue()
	{
		Node*			dummy		= new Node();
		CountedNodePtr	dummy_ptr;
		
		dummy_ptr.external_count	= 1;
		dummy_ptr.ptr 				= dummy;

		head.store( dummy_ptr );
		tail.store( dummy_ptr );
	}
	~LockFreeQueue()
	{
		while ( pop() );		
	}

	void				push( const T& value )
	{
		std::unique_ptr< T >	new_data( new T( value ) );
		CountedNodePtr			new_next;

		new_next.ptr 				= new Node();
		new_next.external_count 	= 1;

		CountedNodePtr	old_tail	= tail.load( std::memory_order_relaxed );
		while ( true )
		{
			increase_external_count( tail, old_tail );
			T* expected = nullptr;
			if ( old_tail.ptr->data.compare_exchange_strong( expected, new_data.get() ) )
			{
				CountedNodePtr old_next{ 0, nullptr };
				if ( old_tail.ptr->next.compare_exchange_strong( old_next, new_next ) );
				else
				{
					delete new_next.ptr;
					new_next = old_next;
				}
				set_new_tail( old_tail, new_next );
				new_data.release();
				break;
			}
			else
			{
				CountedNodePtr old_next{ 0, nullptr };
				if ( old_tail.ptr->next.compare_exchange_strong( old_next, new_next ) )
				{
					old_next 				= new_next;
					new_next.ptr			= new Node();
					new_next.external_count = 1;
				}
				set_new_tail( old_tail, new_next );
			}
		}		
	}

	std::unique_ptr< T >	pop()
	{
   		CountedNodePtr old_head = head.load( std::memory_order_relaxed );
    
    	while ( true )
    	{
        	increase_external_count( head, old_head );
        
        	Node* const ptr = old_head.ptr;
        
        	if ( ptr == tail.load().ptr )
       		{
				release_ref( ptr );
       	     	return std::unique_ptr< T >();
			}
			        
        	CountedNodePtr next = ptr->next.load();
        
       		if ( head.compare_exchange_strong( old_head, next ) )
        	{
            	T* const res = ptr->data.exchange( nullptr );
            	free_external_counter( old_head );
            	return std::unique_ptr< T >( res );
        	}        
        	release_ref( ptr );
    	}
	}
};

