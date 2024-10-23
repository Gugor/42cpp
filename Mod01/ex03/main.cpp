#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	/*HumanA witiza("Witiza");
	HumanB unamedB;
	Weapon club = Weapon("Club");
	HumanA recaredo("Recaredo", club);
	HumanB maia("Maia");
	std::cout << std::endl;
	std::cout << "***And the battle starts!***" << std::endl;
	std::cout << std::endl;
	witiza.attack("Maia");
	club.setType("Spikes");
	unamedB.attack("Witiza");
	recaredo.attack("himself");
	maia.attack("Recaredo");
	std::cout << std::endl;
	std::cout << "***And the battle ends!***" << std::endl;
	std::cout << std::endl;*/
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();

	}
}