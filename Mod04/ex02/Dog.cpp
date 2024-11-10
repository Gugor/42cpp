 #include "Dog.hpp"

Dog::Dog(void) 
{
	this->_type = "Dog";
	this->_mybrain = new Brain();
	std::cout << "> A new Dog has being breeded!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		this->_mybrain = new Brain();
		std::cout << "> A new Dog has being breeded from another!" << std::endl;
	}
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other.getAnimalType();
		this->_mybrain = new Brain();
		std::cout << "> A new Dog has being breeded asigned from another!" << std::endl;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_mybrain;
	std::cout << "> An Dog has ceased to exist in this realm of us" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "> The Dog says: wauf wauf, wuuurf" << std::endl;
}

std::string Dog::getAnimalType(void) const
{
	return (this->_type);
}
