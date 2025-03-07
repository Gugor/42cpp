#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
std::cout << ":: ScalarConverter has been created." << std::endl; 
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: ScalarConverter has been deep copied." << std::endl; 
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
if (this != &other)
{
	this->_name = other.getName();
}
std::cout << ":: ScalarConverter has been deep assigned." << std::endl; 
return (*this);
}

ScalarConverter::~ScalarConverter(void){}

std::string ScalarConverter::getName(void) const
{
return (this->_name);
}

