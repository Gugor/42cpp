#include "AMateria.hpp"

AMateria::AMateria(const AMateria &other)
{
	if (this != &other)
	{
		*this = other;
	}
}

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

AMateria *AMateria::clone() const
{
	if (!this)
		return ;
	return (new Materia(this));
}

void AMateria::use(ICharacter &target)
{
	std::cout << this->ICharacter::getName() << " cast an undefined materia onto " << other->getName() << std::endl; 
}




