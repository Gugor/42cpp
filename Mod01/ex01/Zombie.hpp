#ifndef ZOMBIE_H
#define ZOMBIE_H

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();

		void setName(std::string name);
		void announce(void);
};
#endif