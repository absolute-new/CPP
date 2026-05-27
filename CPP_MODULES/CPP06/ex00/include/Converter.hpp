#ifndef CLASS_CONVERTER_HPP
# define CLASS_CONVERTER_HPP

# include <string>
# include <iostream>

class Converter
{
private:
	enum 		_Type { DEFAULT, CHAR, INT, FLOAT, DOUBLE, NON_NUM };
	enum		_e_flags
	{
		OK = 0x00,		
		CHAR_OVERFLOW = 0x01,
		INT_OVERFLOW = 0x02,
		CHAR_UNPRINTABLE = 0x04
	};

	std::string	_input;
	_Type		_type;
	int			_eFlags;
	char		_asChar;
	int			_asInt;
	float		_asFloat;
	double		_asDouble;

public:
	Converter(void);
	Converter(const std::string& input);
	Converter(Converter const& other);
	~Converter(void);

	Converter& operator=(Converter const& other);

	char		getAsChar(void) const;
	int			getAsInt(void) const;
	float		getAsFloat(void) const;
	double		getAsDouble(void) const;
	bool		isCharOk(void) const;
	bool		isIntOk(void) const;
	std::string	getCharMessage(void) const;

private:
	void			_detect_type(const std::string& input);
	void			_extractType(const std::string& input);
	void			_castFromChar(void);
	void			_castFromInt(void);
	void			_castFromFloat(void);
	void			_castFromDouble(void);
	void			_setConversionEFlags(void);
	bool			_isChar(std::string const& input);
	bool			_isInt(std::string const& input);
	bool			_isFloat(std::string const& input);
	bool			_isDouble(std::string const& input);
	bool			_isNonNumeric(std::string const& input);
};

std::ostream&	operator<<(std::ostream& os, Converter const& converter);

#endif