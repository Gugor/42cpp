#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		~Ice(void);

		AMateria *clone() const;
		std::string const &getType(void) const;
		void use (ICharacter &target);
};

#endif
