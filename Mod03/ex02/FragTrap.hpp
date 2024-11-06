#ifndef FRAGTRAP_H
#define FRAGTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap &operator=(const ClapTrap &other);
		~FragTrap();

		void attack(const std::string &target);
		void guardGate(void);
		void highFivesGuys(void);
};


#endif
