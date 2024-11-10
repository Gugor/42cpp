#ifndef CURE_H
#define CURE_H

#include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		AMateria *clone(void) const;
		void use (ICharacter &target);
};

#endif
