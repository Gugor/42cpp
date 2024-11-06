#ifndef FLAGTRAP_H
#define FLAGTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include <iostream>

class FlagTrap: public ClapTrap
{
	public:
		FlagTrap(void);
		FlagTrap(const std::string name);
		FlagTrap &operator=(const ClapTrap &other);
		~FlagTrap();

		void attack(const std::string &target);
		void guardGate(void);
		void highFivesGuys(void);
};


#endif
