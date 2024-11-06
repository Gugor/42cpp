#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	this->_name = "FlagTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "> A new FlagTrap has being assembled! poor him has no name..." << std::endl; 
}

FlagTrap::FlagTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "> FlagTrap" << name << " has being assembled!" << std::endl; 
}

FlagTrap &FlagTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergy();
		this->_attackDamage = other.getDamage();
		std::cout << "> FlagTrap " << this->_name << " has being assembled successfully form an old blueprint" << std::endl;
	}
	return (*this);
}

FlagTrap::~FlagTrap(void)
{
	std::cout << "> FlagTrap " << this->_name << " has being disassembled and throwed to the junkyard..." << std::endl;
}

void FlagTrap::attack(const std::string &target)
{
        std::cout << "> SrcavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
	std::cout << "> FlagTrap " << this->_name << " rises its robotic arm showing the palm. High Fives! he says" << std::endl;
}
