#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(const AMateria &other)
{
	if (this != &other)
	{
		*this = other;
	}
}

AMateria::AMateria(void){}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

AMateria::~AMateria(void) {}

void AMateria::use(int indx, ICharacter &target)
{
	// std::cout << this->ICharacter::getName() << " cast an undefined materia onto " << other->getName() << std::endl; 
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

