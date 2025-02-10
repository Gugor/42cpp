#include "Ice.hpp"

Ice::Ice(void)
{
	this->_type = std::string("Ice");	
}

Ice::Ice(const Ice &other)
{
	if (this != &other)
	{
		this->_type = other.getType();
	}
}

Ice::~Ice(void){}

AMateria *Ice::clone() const
{
	if (!this)
		return (0);
	
	return (new Ice(*this));
}

std::string const &Ice::getType(void) const
{
	return (this->_type);
}

void Ice::use(ICharacter &target)
{
	
}
