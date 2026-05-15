#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) :_value( 0 ) {}
Fixed::Fixed( const int value ) : _value( value << _fractional_bits ) {}
Fixed::Fixed( const float value )
{
	_value = roundf( value * ( 1 << _fractional_bits ) );
}

Fixed::~Fixed( void ) {}

Fixed::Fixed( const Fixed& other ) : _value( other.getRawBits () ) {}
Fixed&			Fixed::operator=( const Fixed& other )
{
	if ( this != &other)
		this->_value = other.getRawBits();
	return ( *this );
}

int				Fixed::getRawBits( void ) const
{
	return ( this->_value );
}

void			Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float			Fixed::toFloat( void ) const
{
	return ( (float)_value / ( 1 << _fractional_bits ) );
}

int				Fixed::toInt( void ) const
{
	return ( _value >> _fractional_bits );
}

std::ostream& 	operator <<( std::ostream& os, const Fixed& fixed )
{
	os << fixed.toFloat();
	return ( os );
}

bool			Fixed::operator>( const Fixed& other ) const
{
	return ( _value > other.getRawBits() );
}

bool			Fixed::operator<( const Fixed& other ) const
{
	return ( _value < other.getRawBits() );
}

bool			Fixed::operator>=( const Fixed& other ) const
{
	return ( _value >= other.getRawBits() );
}

bool			Fixed::operator<=( const Fixed& other ) const
{
	return ( _value <= other.getRawBits() );
}

bool			Fixed::operator==( const Fixed& other ) const
{
	return ( _value == other.getRawBits() );
}

bool			Fixed::operator!=( const Fixed& other ) const
{
	return ( _value != other.getRawBits() );
}

Fixed			Fixed::operator+( const Fixed& other ) const
{
	Fixed	result;
	result.setRawBits( _value + other.getRawBits() );
	return ( result );
}

Fixed			Fixed::operator-( const Fixed& other ) const
{
	Fixed	result;
	result.setRawBits( _value - other.getRawBits() );
	return ( result );
}

Fixed			Fixed::operator*( const Fixed& other ) const
{
	Fixed		result;
	long long	temp;

	temp = ( long long )_value * other.getRawBits();	
	result.setRawBits( temp >> _fractional_bits );
	return ( result );
}

Fixed			Fixed::operator/( const Fixed& other ) const
{
	Fixed		result;
	long long	temp;

	temp = ( long long )_value * ( 1 << _fractional_bits );	
	result.setRawBits( temp / other.getRawBits() );
	return ( result );
}

Fixed			Fixed::operator++( int )
{
	Fixed	temp = *this;
	++( *this );
	return ( temp );
}

Fixed			Fixed::operator--( int )
{
	Fixed	temp = *this;
	--( *this );
	return ( temp );
}

Fixed&			Fixed::operator++( void )
{
	_value += 1;
	return ( *this );
}

Fixed&			Fixed::operator--( void )
{
	_value -= 1;
	return ( *this );
}

Fixed&			Fixed::min( Fixed& a, Fixed& b )
{
	if ( a < b )
		return ( a );
	return ( b );
}

Fixed&			Fixed::max( Fixed& a, Fixed& b )
{
	if ( a > b )
		return ( a );
	return ( b );
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if ( a < b )
        return ( a );
    return ( b );
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
    if ( a > b )
        return ( a );
    return ( b );
}
