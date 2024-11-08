#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "WrongCat";
	std::cout << "> A new WrongCat has being breeded!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		std::cout << "> A new WrongCat has being breeded from another!" << std::endl;
	}
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		std::cout << "> A new WrongCat has being breeded assigned from another!" << std::endl;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "> An WrongCat has ceased to exist in this realm of us" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "> The cat says: meeeeeeaaaooooowww wroooonggg. Crazy this cat innit? " << std::endl;
}

std::string WrongCat::getAnimalType() const
{
	return ((std::string)this->_type);
}
