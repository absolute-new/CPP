#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <mutex>

# define MAX_HAZARD_POINTER 10

std::mutex	cout_mtx;

struct Hazard_pointer
{
	std::atomic< std::thread::id >	owner_id;
	std::atomic< void * >			ptr;

	Hazard_pointer() : owner_id( std::thread::id() ), ptr( nullptr ) {}
};

static Hazard_pointer	g_hazard_pointers[ MAX_HAZARD_POINTER ];

class	HazardPointerOwner
{
private:
	Hazard_pointer	*my_hp;
	
public:
	HazardPointerOwner() : my_hp( nullptr )
	{
		for ( int i = 0; i < MAX_HAZARD_POINTER; ++i )
		{
			std::thread::id	empty_id;

			if ( g_hazard_pointers[ i ].owner_id.compare_exchange_strong( empty_id, std::this_thread::get_id() ) )
			{
				my_hp = &g_hazard_pointers[ i ];
				break;
			}
		}

		if ( !my_hp )
			throw std::runtime_error( "Not free hazard pointers" );
	}
	~HazardPointerOwner()
	{
		if ( my_hp )
		{
			my_hp->ptr = nullptr;
			my_hp->owner_id.store( std::thread::id() );
		}
	}

	std::atomic< void* >&	get_pointer()
	{
		return ( my_hp->ptr );
	}		
};

std::atomic< void* >&	get_hazard_pointer()
{
	thread_local static	HazardPointerOwner	owner;
	return ( owner.get_pointer() );
}

bool					has_hazard_pointers_for( void* ptr )
{
	for ( int i = 0; i < MAX_HAZARD_POINTER; ++i )
	{
		if ( g_hazard_pointers[ i ].ptr.load() == ptr )
			return ( true );
	}
	return ( false );
}

struct DeferredNode
{
	void*			data;
	void			( *deleter )( void* );
	DeferredNode*	next;

	template< typename U >
	DeferredNode( U* ptr ) : data( ptr ), deleter( []( void* p ) { delete static_cast< U* >( p ); } ),
		next( nullptr ) {}
};

static std::atomic< DeferredNode* >	g_deferred_list{ nullptr };

void					add_to_deferred_list( DeferredNode* node )
{
	node->next = g_deferred_list.load();
	while ( !g_deferred_list.compare_exchange_weak( node->next, node ) );
}

template< typename U >
void					reclaim_later( U* ptr )
{
	add_to_deferred_list( new DeferredNode( ptr ) );
}

void					delete_nodes_with_no_hazards()
{
	DeferredNode*	current = g_deferred_list.exchange( nullptr );

	while ( current )
	{
		DeferredNode*	next = current->next;

		if ( !has_hazard_pointers_for( current->data ) )
		{
			current->deleter( current->data );
			delete current;
		}
		else
			add_to_deferred_list( current );
		current = next;
	}	
}

/* 	Lock - free stack	*/

template< typename T >
class	LockFreeStack
{
private:
	struct	Node
	{
		T					data;
		Node*				next;

		Node( const T& value ) : data( value ), next( nullptr ) {}
	};
	std::atomic< Node* >	head{ nullptr };
	
public:
	void	push( const T& value )
	{
		Node*	new_node = new Node( value );
		new_node->next	 = head.load();

		while ( !head.compare_exchange_weak( new_node->next, new_node ) );		
	}

	T		pop( void )
	{
		auto&	hp 			= get_hazard_pointer();

		while ( true )
		{
			Node*	old_head = head.load();
			hp.store( old_head );

			if ( old_head != head.load() )
				continue;
			if ( old_head == nullptr )
			{
				hp.store( nullptr );
				throw std::runtime_error( "Stack is empty" );
			}
			if ( head.compare_exchange_weak( old_head, old_head->next ) )
			{
				T	result = old_head->data;
				hp.store( nullptr );

				if ( has_hazard_pointers_for( old_head ) )
					reclaim_later( old_head );
				else
					delete old_head;

				delete_nodes_with_no_hazards();

				return ( result );
			}
		}	
	}
};


int main( void )
{

	LockFreeStack< int >		stack;
	LockFreeStack< int >		stack2;
	std::vector< std::thread >	threads;

	std::cout << "=== Lock-free стек с Hazard Pointers ===\n\n";

	stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;

	std::cout << "=======test threads======\n\n" << std::endl; 

	for ( int i = 0; i < 100; ++i )
        stack2.push(i);
	
	for ( int j = 0; j < 5; ++j )
	{
		threads.emplace_back( [&stack2, j] ()
		{
			for ( int i = 0; i < 20; ++i )
			{
				try
				{
					int	val = stack2.pop();
					std::lock_guard< std::mutex >	lock( cout_mtx );
					std::cout << "thread: " << j << " pop: " << val << std::endl;
				}
				catch( const std::runtime_error& )
				{
					std::lock_guard< std::mutex >	lock( cout_mtx );
					std::cout << "thread: " << j << " - stack empty" << std::endl;
				}
				stack2.push( j * 100 + i );
			}
		} );
	}
	 for ( auto& t : threads )
        t.join();

	return ( 0 );
}