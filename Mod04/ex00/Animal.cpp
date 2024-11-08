#include "Animal.hpp"

Animal::Animal(void) 
{
	this->_type = "Animal";
	std::cout << "> An indeterminated animal has born!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
	}
	std::cout << "> An Animal of type " << this->_type  << " has born from another!" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
	}
	std::cout << "> An Animal of type " << this->_type  << " has born assigned from another!" << std::endl;
	return (*this);
}

Animal::Animal(const std::string type)
{
	this->_type = type;
	std::cout << "> An Animal of type " << this->_type  << " has born and labeled!" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "> An indeterminiated animal has ceased to exist in this realm of us" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "> I am an indeterminated animal so what sound should I do?" << std::endl;
}

std::string Animal::getAnimalType(void) const
{
	return (this->_type);
}

