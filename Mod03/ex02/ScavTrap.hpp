#ifndef SCAVTRAP_H
#define SCAVTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap &other);
		ScavTrap(const std::string name);
		ScavTrap &operator=(const ClapTrap &other);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate(void);
};


#endif
