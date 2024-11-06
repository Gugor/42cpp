#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "> A new ScavTrap has being assembled! poor him has no name..." << std::endl; 
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "> ScavTrap" << name << " has being assembled!" << std::endl; 
}

ScavTrap &ScavTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergy();
		this->_attackDamage = other.getDamage();
		std::cout << "> ScavTrap " << this->_name << " has being assembled successfully form an old blueprint" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "> ScavTrap " << this->_name << " has being disassembled and throwed to the junkyard..." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
        std::cout << "> SrcavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "> ScavTrap " << this->_name << " is kindly guarding the gate. Such a delightfull robot!!" << std::endl;
}
