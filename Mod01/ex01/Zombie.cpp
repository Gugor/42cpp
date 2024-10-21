#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "Some Zombie";
	std::cout << this->_name << " has rised from the death. The lines of the undead grow!" << std::endl;
}
void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " has rised from the death. The lines of the undead grow!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name <<" has being killed! The undeads cray their lost... or not" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}