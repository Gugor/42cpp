#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;	
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		~AMateria(void);

		std::string const &getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(int indx, ICharacter &target);
};

#endif
