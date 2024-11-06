#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <string>
# include <iostream>

class ClapTrap
{
	protected:
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
		int getHitPoints(void) const;
		std::string getName(void) const;
		unsigned int getEnergy(void) const;
		unsigned int getDamage(void) const;
		void setAttackDamage(unsigned int amount);
		void setEnergy(unsigned int energy);
		void setDamage(unsigned int damage);
		int useEnergy(void);
		void showStatus(void);
};


#endif
