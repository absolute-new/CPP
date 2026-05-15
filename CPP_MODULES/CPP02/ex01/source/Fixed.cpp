#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) :_value( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) : _value( value << _fractional_bits )
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf( value * ( 1 << _fractional_bits ) );
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &other)
		this->_value = other.getRawBits();
	return ( *this );
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_value );
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ( (float)_value / ( 1 << _fractional_bits ) );
}

int		Fixed::toInt( void ) const
{
	return ( _value >> _fractional_bits );
}

std::ostream& operator <<( std::ostream& os, const Fixed& fixed )
{
	os << fixed.toFloat();
	return ( os );
}
