#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

#define MATS_MX

class Character
{
	private:
		std::string _name;
		AMateria *_invetory[MATS_MX];
		int _matsEquiped;
	public:
		Character(void);
		Character(std::string name);
		Character(const ICharacter &other);
		Character &operator=(const Icharacter &other);
		~Character(void);
	
		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, Icharacter &target);
};

endif
