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
			if (other.getMateria(i))
			{
				this->_grimoire[i] = other.getMateria(i).clone();	
				this->_numMaterias++;
			}
		}
	}
}

IMateriaSource &MateriaSource::operator=(const IMateriaSource &other)
{
	if (this != &other)
	{
		delete [] this->_grimoire;
		this->_numMaterias = 0;
		for (int i=0; i < other.getSize(); i++)
		{
			if (other.getMateria(i))
			{
				this->_grimoire[i] = other.getMateria(i).clone();	
				this->_numMaterias++;
			}
		}
		this->_size = GRIM_SIZE; 
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	delete [] this->_girmoire;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (this->_numMaterias >= GRIM_SIZE)
	{
		std::cout << "> Max number of materias reached. The source cannot learn more materias."
	}
	while (this->_grimoire[i])
		i++;
	if (i < GRIM_SIZE)
	{
		this->_grimoire[i] = mat;
		this->_numMaterias++;
	}
}

AMateria *createMateria(std::string const &type)
{
	for(int i=0; i < this->_numMaterias; i++)
	{
		if (this->_girmoire[i].getType() == type)
		{
			return (new Materia(type));
		}

	}
}
