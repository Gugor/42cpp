#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->_type = name;
	std::cout << "> " << "New weapon forged of type " << this->_type << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "> " << this->_type << " has being destroyed" << std::endl;
	return ;
}

const std::string &Weapon::getType(void)
{
	return (this->_type);	
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "> New weapon forged of type " << this->_type << std::endl;
}
