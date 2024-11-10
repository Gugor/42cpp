#ifndef ICE_H
#define ICE_H

#include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		AMateria *clone() const;
		void use (ICharacter &target);
};

#endif
