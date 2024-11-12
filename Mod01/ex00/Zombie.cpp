#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " has risen from death. The lines of the undead grow!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name <<" has been killed! The undeads cry their lost... or not" << std::endl;
	return ;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

