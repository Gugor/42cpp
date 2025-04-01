#include "MutantStack.hpp"

MutantStack::MutantStack(void)
{
	std::cout << ":: MutantStack has been created." << std::endl; 
}

MutantStack::MutantStack(const MutantStack &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
	}
	std::cout << ":: MutantStack has been deep copied." << std::endl; 
}
MutantStack &MutantStack::operator=(const MutantStack &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
	}
	std::cout << ":: MutantStack has been deep assigned." << std::endl; 
	return (*this);
}

MutantStack::~MutantStack(void){}

std::string MutantStack::getName(void) const
{
	return (this->_name);
}

