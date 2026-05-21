#include "Converter.hpp"
#include <sstream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cerrno>

Converter::Converter(void) : _type(DEFAULT), _eFlags(OK), _asChar(0),
	_asInt(0), _asFloat(0), _asDouble(0) {}

Converter::Converter(const std::string& input) : _input(input),
	_type(DEFAULT),	_eFlags(OK), _asChar(0), _asInt(0), _asFloat(0),
	_asDouble(0)
{
	_detect_type(_input);
}

Converter::Converter(Converter const& other) : _type(other._type),
	_eFlags(other._eFlags), _asChar(other._asChar),
	_asInt(other._asInt), _asFloat(other._asFloat), _asDouble(other._asDouble) {}

Converter::~Converter(void) {}

Converter& Converter::operator=(Converter const& other)
{
	if (this != &other)
	{
		_input = other._input;
		_type = other._type;
        _eFlags = other._eFlags;
        _asChar = other._asChar;
        _asInt = other._asInt;
        _asFloat = other._asFloat;
        _asDouble = other._asDouble;
	}
	return (*this);
}

bool	Converter::_isChar(std::string const& input)
{
    if (input.empty())
        return (false);
    if (input.length() == 1 && !std::isdigit(input[0]))
    {
        _asChar = input[0];
        return (true);
    }
    return (false);
}

bool	Converter::_isInt(std::string const& input)
{
	char	*end;
	long	nb;

	nb = std::strtol(input.c_str(), &end, 10);
	if (end == input.c_str())
		return (false);
	if (*end != '\0')
		return (false);
	if (nb > std::numeric_limits<int>::max()
		|| nb < std::numeric_limits<int>::min())
		return (false);
	_asInt = static_cast<int>(nb);
	return (true);
}

bool	Converter::_isFloat(std::string const& input)
{
	char	*end;
	float	nb;

	nb = std::strtof(input.c_str(), &end);
	if (end == input.c_str())
		return (false);
	if (*end != '\0' && *end != 'f')
		return (false);
	if (*end == 'f' && *(end + 1) != '\0')
		return (false);
	if (std::isinf(nb) && errno == ERANGE)
	{
		_asFloat = std::numeric_limits<float>::infinity();
		return (true);
	}
	if (nb > std::numeric_limits<float>::max()
		|| nb < -std::numeric_limits<float>::max())
		return (false);
	if (std::isnan(nb))
    	return (false);
	_asFloat = nb;
	return (true);
}

bool	Converter::_isDouble(std::string const& input)
{
    char	*end;
    double	nb;
	
	nb = std::strtod(input.c_str(), &end);
    if (end == input.c_str())
        return false;
    if (*end != '\0' && *end != 'f')
        return false;
    if (*end == 'f' && *(end + 1) != '\0')
        return false;
    if (nb > std::numeric_limits<double>::max() || nb < -std::numeric_limits<double>::max())
        return false;
    _asDouble = nb;
    return true;
}

bool	Converter::_isNonNumeric(std::string const& input)
{
	if (input == "nan" || input == "nanf")
	{
		_eFlags |= INT_OVERFLOW;
		_eFlags |= CHAR_OVERFLOW;
		_asFloat = std::numeric_limits<float>::quiet_NaN();
		_asDouble = std::numeric_limits<double>::quiet_NaN();
		return (true);
	}
	if (input == "inf" || input == "+inf"
		|| input == "inff" || input == "+inff")
	{
		_eFlags |= INT_OVERFLOW;
		_eFlags |= CHAR_OVERFLOW;
		_asFloat = std::numeric_limits<float>::infinity();
		_asDouble = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (input == "-inf" || input == "-inff")
	{
		_eFlags |= INT_OVERFLOW;
		_eFlags |= CHAR_OVERFLOW;
		_asFloat = -std::numeric_limits<float>::infinity();
		_asDouble = -std::numeric_limits<double>::infinity();
		return (true);
	}
    return false;
}

void	Converter::_detect_type(std::string const& input)
{
	_extractType(input);
	switch (_type)
	{
	case CHAR:
		_castFromChar();
		break;
	case INT:
		_castFromInt();
		break;
	case FLOAT:
		_castFromFloat();
		break;
	case DOUBLE:
		_castFromDouble();
		break;
	case NON_NUM:
		break;
	default:
		break;
	}
}

void	Converter::_castFromChar(void)
{
	_asInt = static_cast<int>(_asChar);
	_asFloat = static_cast<float>(_asChar);
	_asDouble = static_cast<double>(_asChar);
	_setConversionEFlags();
}

void	Converter::_castFromInt(void)
{
	_asChar = static_cast<char>(_asInt);
	_asFloat = static_cast<float>(_asInt);
	_asDouble = static_cast<double>(_asInt);
	_setConversionEFlags();
}

void	Converter::_castFromFloat(void)
{
	_asChar = static_cast<char>(_asFloat);
	_asInt = static_cast<int>(_asFloat);
	_asDouble = static_cast<double>(_asFloat);
	_setConversionEFlags();
}

void	Converter::_castFromDouble(void)
{
	_asChar = static_cast<char>(_asDouble);
	_asInt = static_cast<int>(_asDouble);
	_asFloat = static_cast<float>(_asDouble);
	_setConversionEFlags();
}

void	Converter::_extractType(std::string const& input)
{
	if (_isNonNumeric(input))
		_type = NON_NUM;
	else if (_isDouble(input))
		_type = DOUBLE;
	else if (_isFloat(input))
		_type = FLOAT;
	else if (_isInt(input))
		_type = INT;
	else if (_isChar(input))
		_type = CHAR;
}

void	Converter::_setConversionEFlags(void)
{
	if (_asInt > std::numeric_limits<char>::max()
		|| _asInt < std::numeric_limits<char>::min())
		_eFlags |= CHAR_OVERFLOW;
	if (!std::isprint(_asChar))
		_eFlags |= CHAR_UNPRINTABLE;

	if (_asFloat > std::numeric_limits<int>::max()
		|| _asFloat < std::numeric_limits<int>::min())
		_eFlags |= INT_OVERFLOW;
	if (_asFloat > std::numeric_limits<char>::max()
		|| _asFloat < std::numeric_limits<char>::min())
		_eFlags |= CHAR_OVERFLOW;
	if (!std::isprint(static_cast<char>(_asFloat)))
		_eFlags |= CHAR_UNPRINTABLE;
	
	if (_asDouble > std::numeric_limits<int>::max()
		|| _asDouble < std::numeric_limits<int>::min())
		_eFlags |= INT_OVERFLOW;
	if (_asDouble > std::numeric_limits<char>::max()
		|| _asDouble < std::numeric_limits<char>::min())
		_eFlags |= CHAR_OVERFLOW;
	if (!std::isprint(static_cast<char>(_asDouble)))
		_eFlags |= CHAR_UNPRINTABLE;	
}

std::string	Converter::getCharMessage(void) const
{
	if (_eFlags & CHAR_OVERFLOW)
		return ("impossible");
	if (_eFlags & CHAR_UNPRINTABLE)
		return ("Non displayable");
	return ("Unknown error");
}

char	Converter::getAsChar(void) const
{
	return (_asChar);
}

int		Converter::getAsInt(void) const
{
	return (_asInt);
}

float	Converter::getAsFloat(void) const
{
	return (_asFloat);
}

double	Converter::getAsDouble(void) const
{
	return (_asDouble);
}

bool	Converter::isCharOk(void) const
{
	return !(_eFlags & (CHAR_OVERFLOW | CHAR_UNPRINTABLE));
}

bool	Converter::isIntOk(void) const
{
	return !(_eFlags & INT_OVERFLOW);
}

std::ostream& operator<<(std::ostream& os, Converter const& converter)
{
	os << "char: ";
	if (!converter.isCharOk())
		os << converter.getCharMessage();
	else
		os << "\'" << converter.getAsChar() << "'";
	os << std::endl;
	
	os << "int: ";
	if (!converter.isIntOk())
		os << "impossible";
	else
		os << converter.getAsInt();
	os << std::endl;
	
	os << "float: ";
	if (converter.getAsFloat() == static_cast<int>(converter.getAsFloat()))
		os << std::fixed << std::setprecision(1) << converter.getAsFloat()
			<< "f";
	else
		os << converter.getAsFloat() << "f";
	os << std::endl;

	os << "double: ";
	os << converter.getAsDouble();
	os << std::endl;
	return (os);
}