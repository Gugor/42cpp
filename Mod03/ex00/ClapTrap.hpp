#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap
{
	private:
	std::string	_name;
	int		_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	
	bool _isJunked(void);	

	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getAttackDamage(void);
		int getHitPoints(void);
		void setAttackDamage(unsigned int amount);
};


#endif
