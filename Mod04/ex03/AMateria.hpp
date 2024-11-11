#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;	
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		~AMateria(void);

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
