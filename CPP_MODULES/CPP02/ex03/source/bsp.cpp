#include "Point.hpp"

static Fixed sign( Point const& v1, Point const& v2, Point const& p)
{
	Fixed	part1;
	Fixed	part2;

	part1 = ( p.getX() - v1.getX() ) * ( v2.getY() - v1.getY() );
	part2 = ( v2.getX() - v1.getX() ) * ( p.getY() - v1.getY() );
	return ( part1 - part2 );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	s1;
	Fixed	s2;
	Fixed	s3;
	bool	all_positive;
	bool	all_negative;
	bool	all_on_side;

	s1 				= sign( a, b, point );
	s2				= sign( b, c, point );
	s3 				= sign( c, a, point );
	all_positive	= ( s1 > 0 ) && ( s2 > 0 ) && ( s3 > 0 );
	all_negative	= ( s1 < 0 ) && ( s2 < 0 ) && ( s3 < 0 );
	all_on_side		= ( s1 != 0 ) && ( s2 != 0 ) && ( s3 != 0 );
	return ( ( all_positive || all_negative ) && all_on_side );
}
