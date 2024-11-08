#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "> A new Cat has being breeded!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		std::cout << "> A new Cat has being breeded from another!" << std::endl;
	}
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		std::cout << "> A new Cat has being breeded assigned from another!" << std::endl;
	}
	return (*this);
}

Cat::~Cat(void)
{
		std::cout << "> An Cat has ceased to exist in this realm of us" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "> The cat says: meeeeeeaaaooooowww. Crazy this cat innit? " << std::endl;
}

std::string Cat::getAnimalType() const
{
	return ((std::string)this->_type);
}
