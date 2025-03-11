#include "Serializer.hpp"

Serializer::Serializer(void)
{
std::cout << ":: Serializer has been created." << std::endl; 
}

Serializer::Serializer(const Serializer &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: Serializer has been deep copied." << std::endl; 
}
Serializer &Serializer::operator=(const Serializer &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: Serializer has been deep assigned." << std::endl; 
return (*this);
}

Serializer::~Serializer(void){}

std::string Serializer::getName(void) const
{
return (this->_name);
}

