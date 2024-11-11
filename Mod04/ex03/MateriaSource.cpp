#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->_grimoire = {NULL, NULL, NULL, NULL}
	this->_numMaterias = 0;
	this->_size = GRIM_SIZE;
}

MateriaSource::MateriaSource(conts IMateriaSource &other)
{
	if (this != &other)
	{
		delete [] this->_grimoire;
		this->_numMaterias = 0;
		for (int i=0; i < other.getSize(); i++)
		{
			this->_grimoire[i] = other.getMateria(i).clone();	
		}
	}
}
