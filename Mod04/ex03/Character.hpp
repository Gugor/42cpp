#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

#define MATS_MX

class Character
{
	public:
		Character(void);
		Character(std::string name);
		Character(const ICharacter &other);
		Character &operator=(const ICharacter &other);
		~Character(void);
	
		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
	private:
		std::string _name;
		int _matsEquiped;
		AMateria *_invetory[MATS_MX];
};

#endif
