#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "> A new FragTrap has being assembled! poor him has no name..." << std::endl; 
}

FragTrap::FragTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "> FragTrap" << name << " has being assembled!" << std::endl; 
}

FragTrap &FragTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergy();
		this->_attackDamage = other.getDamage();
		std::cout << "> FragTrap " << this->_name << " has being assembled successfully form an old blueprint" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "> FragTrap " << this->_name << " has being disassembled and throwed to the junkyard..." << std::endl;
}

void FragTrap::attack(const std::string &target)
{
        std::cout << "> SrcavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "> FragTrap " << this->_name << " rises its robotic arm showing the palm. High Fives! he says" << std::endl;
}
