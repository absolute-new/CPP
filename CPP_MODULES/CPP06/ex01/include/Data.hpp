#ifndef DATA_CLASS_HPP
# define DATA_CLASS_HPP

# include <string>
# include <stdint.h>

struct Data
{
	std::string	name;
	int			value;
};

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif
