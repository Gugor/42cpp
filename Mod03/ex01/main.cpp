#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Lights;	
	ClapTrap beam("Boom");	
	ScavTrap LightsV2;
	std::cout << std::endl;

	Lights = ClapTrap("Lights");
	LightsV2 = Lights;
	std::cout << std::endl;

	Lights.attack("Lights");
	LightsV2.takeDamage(Lights.getDamage());
	std::cout << "> LightsV2 supercharges go berserker. ";
	LightsV2.setAttackDamage(8);
	LightsV2.attack("Lights");
	Lights.takeDamage(LightsV2.getDamage());
	Lights.getHitPoints();
	std::cout << "> LightsV2 so quickly attacks again. ";
	LightsV2.attack("Lights");
	Lights.takeDamage(LightsV2.getDamage());
	Lights.showStatus();
	beam.setAttackDamage(3);
	std::cout << "> Boom takes advantage of this carnage and attacks LightsV2 from behind" << std::endl;
	beam.attack("Lights");
	Lights.takeDamage(beam.getDamage());
	Lights.showStatus();
	std::cout << "> Surprisingly as soon as LightsV2 takes damage, it's automatic repairing systems activates itself. " << std::endl;
	LightsV2.beRepaired(1);
	LightsV2.showStatus();

	std::cout << std::endl;
	LightsV2.guardGate();
	std::cout << "> The screen goes black for a second and then display the letters: To be continued..." << std::endl;
	std::cout << std::endl;
}
