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

		void highFivesGuys(void);
};


#endif
