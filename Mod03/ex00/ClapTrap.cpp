#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "ClapTrap";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "> A new ClapTrap has being assembled! poor him has no name..." << std::endl; 
}

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "> " << name << " has being assembled!" << std::endl; 
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "> " << this->_name << " has being assembled successfully form an old blueprint" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "> " << this->_name << " has being disassembled and throwed to the junkyard..." << std::endl;
}

bool ClapTrap::_isJunked(void)
{
	if (this->_hitPoints <= 0)
		return true;
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "> ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_isJunked())
	{
		std::cout << "> Don't boder, this ClapTrap has being emptied from every drop of oil! Shall we se again in the heaven of robots..." << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "> " << this->_name << " has being attacked. Has suffered " << amount << " damage. Clunk!! a hollow sound echoes... " << std::endl;
	if (this->_isJunked())
	{
		std::cout << "> " << this->_name << " is leaking oil every where, and falls like a plank to the ground. Doesn't seem could stand again..." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{	
	if (this->_isJunked())
	{
		std::cout << "> This ClapTrap is beyond repaire! Has lost to much oil..." << std::endl;
		return ;
	}
	std::cout << "> A sound of sparks, and wires being solded.";
	std::cout << this->_name << " has being repaired by " << amount;
	std::cout << " hitPoints! bip bip" << std::endl;
	this->_hitPoints += amount;
}

unsigned int ClapTrap::getAttackDamage(void)
{
	return (this->_attackDamage);
}

int ClapTrap::getHitPoints(void)
{
	std::cout << "> " << this->_name << " has " << this->_hitPoints << " hitpoints" << std::endl;
	return (this->_hitPoints);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	std::cout << "> "<< this->_name << " has change its attack damage to ";
	std::cout << amount << std::endl;
	this->_attackDamage = amount;
}
