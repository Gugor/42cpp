#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>

#define GRIM_SIZE 4

class MateriaSource
{
	private:
		AMateria *_grimoire[GRIM_SIZE];
		unsigned int _numMaterias;
		unsigned int _size;
	public:
		MateriaSource(void);
		MateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
		~IMateriaSource(void);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
		unsigned int getSize() const;
		AMateria *getMateria(int indx);
};

#endif
