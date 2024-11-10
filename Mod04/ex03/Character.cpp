#include "Character.hpp"

Character::Character(void) _name("No name") {}

Character::Character(std::string name)
{
	this->_name = name;
	this->idxInventory = 0;
	this->inventory = {NULL, NULL, NULL, NULL};
}

Character::Character(const ICharacter &other) 
{
	if (this != &other)
	{
		delete[] this->inventory;
		this->_idxInventory = 0;
		for(int i=0; i < MATS_MX; i++)
		{
			this->aquireMateria(other.getInventoryMateria(i), i);
		}
		*this = other;
	}
}

Character &Character::operator=(const ICharacter &other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Character::~Character(void)
{
	delete[] inventory;
}

AMateria &Character::getInventoryMateria(int indx)
{
	return (this->inventory[i]);
}

void Character::aquireMateria(AMateria &mat, int indx)
{
	AMateria *newMateria = new Materia(mat);
	this->_inventory[i] = newMateria; 
	this->idxInventory++;
}
