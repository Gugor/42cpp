#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	std::cout << "> " << this->_name << " has born!" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "> " << this->_name << " has died!" << std::endl;
}

void HumanB::attack()
{
	if (!this->_weapon)
		return ;
	std::cout << "> " << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << "> " << this->_name << " has grabed a weapon!" << std::endl;
}
