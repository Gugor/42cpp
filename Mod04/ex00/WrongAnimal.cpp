#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) 
{
	this->_type = "WrongAnimal";
	std::cout << "> An indeterminated animal has born!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
	}
	std::cout << "> An WrongAnimal of type " << this->_type  << " has born from another!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
	}
	std::cout << "> An WrongAnimal of type " << this->_type  << " has born assigned from another!" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "> An indeterminiated animal has ceased to exist in this realm of us" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type)
{
	this->_type = type;
	std::cout << "> An WrongAnimal of type " << this->_type  << " has born and labeled!" << std::endl;
}


void WrongAnimal::makeSound(void) const
{
	std::cout << "> I am an indeterminated animal so what wrong sound should I do?" << std::endl;
}

std::string WrongAnimal::getAnimalType(void) const
{
	return (this->_type);
}

