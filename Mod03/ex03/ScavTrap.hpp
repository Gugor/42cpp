#ifndef SCAVTRAP_H
#define SCAVTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate(void);
};


#endif
