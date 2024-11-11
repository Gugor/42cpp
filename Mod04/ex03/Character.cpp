#include "Character.hpp"

Character::Character(void) _name("No name") {}

Character::Character(std::string name)
{
	this->_name = name;
	this->_matsEquiped = 0;
	this->_inventory = {NULL, NULL, NULL, NULL};
}

Character::Character(const ICharacter &other) 
{
	if (this != &other)
	{
		delete[] this->_inventory;
		this->_matsEquiped = 0;
		for(int i=0; i < MATS_MX; i++)
		{
			this->equip(other.getInventoryMateria(i).clone());
		}
		this->_name = other._name;
		this->_matsEquiped = other._matsEquiped;	
	}
}

Character &Character::operator=(const ICharacter &other)
{
	if (this != &other)
	{
		delete[] this->_inventory;
		this->_matsEquiped = 0;
		for(int i=0; i < MATS_MX; i++)
		{
			this->equip(other.getInventoryMateria(i).clone());
		}
		this->_name = other._name;
		this->_matsEquiped = other._matsEquiped;	
	}
	return (*this);
}

Character::~Character(void)
{
	delete[] _inventory;
}

void Character::equip(AMateria *mat)
{
	if (this->_idxIventory >= MATS_MX)
	{
		std::cout << "There is no space in inventory, unequip a Materia to free a slot."
		return ;
	}
	unsigned int i;
	this->_matsEquiped++;
	while (this->_inventory[i] && i <= MAT_MX)
		i++;
	if (i < MAT_MX)
		this->_inventory[i] = mat.clone(); 
	delete mat;
}

void Character::unequip(int idx)
{
	if (idx >= MAT_MX)
	{
		srd::cout << "There is no such Materia in " << this->_name << " inventory to be unequiped" << std::endl;
		return ;
	}
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	this->_matsEquiped--;
}

void use(int idx, ICharacter &target)
{
	if (idx >= MAT_MX)
	{
		srd::cout << "There is no such Materia in " << this->_name << " inventory to be used." << std::endl;
		return ;
	}
	this->_inventory[idx].use(target);
}
