#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>

class MateriaSource
{
	public:
		~IMateriaSource() {}
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif
