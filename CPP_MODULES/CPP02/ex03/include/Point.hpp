#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point( void );
	Point( float const a, float const b );
	~Point( void );
	Point( const Point& other );
	Point& operator=( const Point& other );

	Fixed const& getX( void ) const;
	Fixed const& getY( void ) const;
};

#endif