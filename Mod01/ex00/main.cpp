#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main (void)
{
	//Stacked zombie
	Zombie zombie2("Stacked Zombie");
	zombie2.announce();

	//Heaped zombie
	Zombie *zombie1;
	zombie1 = new Zombie("Heaped Zombie");
	zombie1->announce();

	std::cout << std::endl;

	//Function stacked zombie announce itself
	randomChump("Stacked Rezombie");

	std::cout << std::endl;
	//Function heaped zombie creation
	Zombie *zombie11 = newZombie("Heaped Rezombie");
	//Hepade zombie announce itself
	zombie11->announce();
	//zombie11->~Zombie();
	std::cout << std::endl;
	delete zombie11;
	return (0);	
}