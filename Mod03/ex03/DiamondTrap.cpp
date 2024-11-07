#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(void): 
ScavTrap("Unamed scav"),
FragTrap("Unamed frag"),
_name("Unamed diamond")
{
	ClapTrap::setName("Unnamed clap name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "> A new DiamondTrap has being assembled! poor him has no name..." << std::endl; 
}

DiamondTrap::DiamondTrap(const std::string name): 
ClapTrap(name + "_clap_name"),
ScavTrap(name), 
FragTrap (name), 
_name(name)
{
	ClapTrap::setName(name + "_clap_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "> DiamondTrap " << name << " has being assembled!" << std::endl; 
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->ClapTrap::_name = other.ClapTrap::getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergy();
		this->_attackDamage = other.getDamage();
		std::cout << "> DiamondTrap " << this->_name << " has being assembled successfully form an old blueprint" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "> DiamondTrap " << this->_name << " has being disassembled and throwed to the junkyard..." << std::endl;
}

void DiamondTrap::whoami(void)
{
	std::cout << "My clap name is: " << ClapTrap::getName() << " and my diamond name is: " << this->_name << ", wich one do you like the most?" << std::endl;
}
