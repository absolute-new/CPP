#include <memory>
#include <atomic>


template< typename T >
class	LockFreeStack
{
private:
	struct Node;
	struct CountNodePtr
	{
		int		external_count;
		Node*	ptr;
	};
	struct Node
	{
		std::shared_ptr< T >	data;
		std::atomic< int >		internal_count;
		CountNodePtr			next;

		Node( const T& value ) : data( std::make_shared< T >( value ) ),
			internal_count( 0 ), next{ 0, nullptr } {}
	};
	std::atomic< CountNodePtr >	head;
	
	void	increase_head_count( CountNodePtr& old_counter )
	{
		CountNodePtr	new_counter;
		do
		{
			new_counter = old_counter;
			++new_counter.external_count;
		} while ( !head.compare_exchange_strong( old_counter, new_counter ) );		
	}
	
public:
	~LockFreeStack()
	{
		while ( pop() );
	}

	std::shared_ptr< T >	pop()
	{
		CountNodePtr	old_head = head.load( std::memory_order_relaxed );

		while ( true )
		{
			increase_head_count( old_head );
			
			Node* const		ptr = old_head.ptr;
			if ( !ptr )
				return ( std::shared_ptr< T >() );

			CountNodePtr	next = ptr->next;
			if ( head.compare_exchange_strong( old_head, next ) )
			{
				std::shared_ptr< T >	res;
				res.swap( ptr->data );

				int const 	increase = old_head.external_count - 2;
				if ( ptr->internal_count.fetch_add( increase ) == -increase )
					delete ptr;
				return ( res );
			}
			else
			{
				if ( ptr->internal_count.fetch_add( -1 ) == 1 )
					delete ptr;
			}
		}		
	}

	void				push( const T& value )
	{
		CountNodePtr	new_node;

		new_node.ptr 			= new Node( value );
		new_node.external_count = 1;
		new_node.ptr->next 		= head.load( std::memory_order_relaxed );
		while ( !head.compare_exchange_weak( new_node.ptr->next, new_node ) );		
	}
};

