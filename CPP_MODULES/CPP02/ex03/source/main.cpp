#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const p );

static void testSimpleTriangle( void )
{
	Point	a( 0, 0 );
	Point	b( 5, 0 );
	Point	c( 0, 5 );
	
	std::cout << "\n========== Simple Triangle ==========\n" << std::endl;

	Point	p1( 1, 1 );
	std::cout << "Point(1, 1)\t" << ( bsp( a, b, c, p1 ) ? "INSIDE" : "OUTSIDE" ) << std::endl;

	Point	p2( 3, 3 );
	std::cout << "Point(3, 3)\t" << ( bsp( a, b, c, p2 ) ? "INSIDE" : "OUTSIDE" ) << std::endl;

	Point	p3( 0, 3 );
	std::cout << "Point(0, 3) on edge\t" << ( bsp( a, b, c, p3 ) ? "INSIDE" : "OUTSIDE" ) << std::endl;

	Point	p4( 3, 0 );
	std::cout << "Point(3, 0) vertex\t" << ( bsp( a, b, c, p4 ) ? "INSIDE" : "OUTSIDE" ) << std::endl;
}

static void testEquilateralTriangle( void )
{
    std::cout << "\n========== Equilateral Triangle ==========\n" << std::endl;
    
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 3.464f);  // высота = sqrt(3)/2 * 4 ≈ 3.464
    
    Point p1(2, 1);
    std::cout << "Point(2, 1)\t\t" << ( bsp( a, b, c, p1 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p2(2, 2);
    std::cout << "Point(2, 2)\t\t" << ( bsp( a, b, c, p2 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p3(2, 3.5f);
    std::cout << "Point(2, 3.5)\t\t" << ( bsp( a, b, c, p3 ) ? "INSIDE" : "OUTSIDE") << std::endl;
}

static void testNegativeTriangle( void )
{
    std::cout << "\n========== Triangle with Negative Coordinates ==========\n" << std::endl;
    
    Point a(-3, -2);
    Point b(2, -2);
    Point c(0, 3);
    
    Point p1(0, 0);
    std::cout << "Point(0, 0)\t\t" << ( bsp( a, b, c, p1 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p2(1, 0);
    std::cout << "Point(1, 0)\t\t" << ( bsp( a, b, c, p2 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p3(-1, 0);
    std::cout << "Point(-1, 0)\t\t" << ( bsp( a, b, c, p3 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p4(0, -2);
    std::cout << "Point(0, -2) on edge\t" << ( bsp( a, b, c, p4 ) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    Point p5(0, 3);
    std::cout << "Point(0, 3) vertex\t" << ( bsp( a, b, c, p5 ) ? "INSIDE" : "OUTSIDE") << std::endl;
}


int main( void )
{
	testSimpleTriangle();
	testEquilateralTriangle();
	testNegativeTriangle();
	return ( 0 );
}
