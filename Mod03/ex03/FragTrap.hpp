#ifndef FRAGTRAP_H
#define FRAGTRAP_H
# include <string>
# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void highFivesGuys(void);
};

#endif
