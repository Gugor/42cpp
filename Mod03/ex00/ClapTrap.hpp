#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# define <iostream>
# define <string>

class ClapTrap
{
	private:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
	
	bool _isJunked(void);	

	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap &operand=(const ClapTrap &other);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getAttackDamage(void);
		void setAttackDamage(unsigned int amount);
}


#endif
