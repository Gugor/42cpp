#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main(void)
{
	ClapTrap basic("Thunder");
	ScavTrap Thunder; 
	FlagTrap Rusty ("Rusty");
	std::cout << std::endl;
	Thunder = basic;
	std::cout << std::endl;
	std::cout << "> ScravTap vs FlagTrap, who is going to win?!" << std::endl;
	std::cout << "> Lets check their status:" << std::endl;
	Thunder.showStatus();
	Rusty.showStatus();
	std::cout << "> Shall win the best!!: Round 1" << std::endl;
	Rusty.attack("Thunder");
	Thunder.attack("Thunder");
	std::cout << std::endl;
	std::cout << "> Round 2" << std::endl;
	Thunder.showStatus();
	Rusty.showStatus();
	Rusty.attack("Thunder");
	Thunder.attack("Thunder");
	std::cout << std::endl;
	std::cout << "> Round 3" << std::endl;
	Thunder.showStatus();
	Rusty.showStatus();
	Rusty.attack("Thunder");
	Thunder.attack("Thunder");
	std::cout << std::endl;
	std::cout << "> Round 4" << std::endl;
	Thunder.showStatus();
	Rusty.showStatus();
	Rusty.attack("Thunder");
	Thunder.attack("Thunder");
	std::cout << std::endl;

	Rusty.highFivesGuys();
	std::cout << "> The screen goes black for a second and then display the letters: To be continued..." << std::endl;
	std::cout << std::endl;
}
