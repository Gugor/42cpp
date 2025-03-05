#include "Character.hpp"

Character::Character(void) : _name("No name") {}


Character::Character(std::string name)
{
	this->_name = name;
	this->_matsEquiped = 0;
	this->_inventory = {NULL};
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
		this->_name = other.getName();
		this->_matsEquiped = other.getMaterias();	
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
		this->_name = other.getName();
		this->_matsEquiped = other.getMaterias();	
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
	while (this->_inventory[i] && i <= MATS_MX)
		i++;
	if (i < MATS_MX)
		this->_inventory[i] = mat.clone(); 
	delete mat;
}

void Character::unequip(int idx)
{
	if (idx >= MATS_MX)
	{
		std::cout << "There is no such Materia in " << this->_name << " inventory to be unequiped" << std::endl;
		return ;
	}
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
	this->_matsEquiped--;
}


void Character::use(int idx, ICharacter &target)
{
	if (idx >= MATS_MX)
	{
		std::cout << "There is no such Materia in " << this->_name << " inventory to be used." << std::endl;
		return ;
	}
	this->_inventory[idx].use(target);
}
