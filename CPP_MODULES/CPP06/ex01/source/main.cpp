#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data		data;
	uintptr_t	serializePtrAsInt;
	Data		*deserializePtr;

	data.name = "Hello, World!";
	data.value = 42;
	serializePtrAsInt = serialize(&data);
	deserializePtr = deserialize(serializePtrAsInt);
	if (deserializePtr == &data)
		std::cout << "Sucessful serialization and deserialization"
			<< std::endl;
	else
		std::cout << "Failed serialization and deserialization"
			<< std::endl;

	std::cout << "Original ptr: " << &data << std::endl;
	std::cout << "Restored ptr: " << deserializePtr << std::endl;
	std::cout << "Ptr to data struct serialize to: "
		<< serializePtrAsInt << std::endl;
	return (0);
}