#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamong("Diamong");
	DiamondTrap diamonk("Diamonk");
	std::cout << std::endl;

	diamong.whoami();
	diamonk.whoami();
	diamong.guardGate();
	diamonk.highFivesGuys();
	std::cout << std::endl;


	
	return (0);
}
