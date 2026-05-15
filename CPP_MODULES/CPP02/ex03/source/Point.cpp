#include "Point.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 ) {}

Point::Point( float const a, float const b ) : _x( a ), _y ( b ) {}

Point::~Point( void ) {}

Point::Point( const Point& other ) : _x( other._x ), _y( other._y ) {}

Point& Point::operator=( const Point& other )
{
	if ( this != &other ) {}
	return ( *this );
}

Fixed const& Point::getX( void ) const
{
	return ( _x );
}

Fixed const& Point::getY ( void ) const
{
	return ( _y );
}
