#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(void){}

Serializer::Serializer(const Serializer &other)
{
	if (this != &other)
	{
		*this = other;
	}
}
Serializer &Serializer::operator=(const Serializer &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Serializer::~Serializer(void){}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

std::ostream &operator<<(std::ostream &out, const Data &data)
{
	return (out << "(" << &data << ")[someInt: " << data.someInt << "]"); 
}
