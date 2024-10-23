
#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <memory>

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);
		void attack();
		void setWeapon(Weapon &weapon);
};
#endif