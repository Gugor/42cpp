#ifndef FLAGTRAP_H
#define FLAGTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap(void);
		
		void whoami(void);
};

#endif
