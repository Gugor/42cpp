#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap beam("Boom");	
	ScavTrap Lights;	
	std::cout << std::endl;

	Lights = ScavTrap("Lights");
	std::cout << std::endl;

	ScavTrap LightsV2(Lights);
	LightsV2.setName("LightsV2");
	std::cout << std::endl;

	Lights.attack("Lights");
	LightsV2.takeDamage(Lights.getDamage());
	std::cout << "> LightsV2 supercharges go berserker. ";
	LightsV2.setAttackDamage(50);
	LightsV2.attack("Lights");
	Lights.takeDamage(LightsV2.getDamage());
	Lights.getHitPoints();
	std::cout << "> LightsV2 so quickly attacks again. ";
	LightsV2.attack("Lights");
	Lights.takeDamage(LightsV2.getDamage());
	Lights.showStatus();
	LightsV2.showStatus();
	beam.setAttackDamage(3);
	std::cout << "> Boom takes advantage of this carnage and attacks LightsV2 from behind" << std::endl;
	beam.attack("Lights");
	Lights.takeDamage(beam.getDamage());
	Lights.showStatus();
	beam.showStatus();
	std::cout << "> Surprisingly as soon as Lights takes damage, it's automatic repairing systems activates itself. " << std::endl;
	Lights.beRepaired(20);
	Lights.showStatus();
	std::cout << "> It seems its too late anyways for him. The repair was unsuccesfull." << std::endl;
	std::cout << std::endl;
	std::cout << "> LightsV2 activate its default mode. ";
	LightsV2.guardGate();
	std::cout << "> The screen goes black for a second and then display the letters: To be continued..." << std::endl;
	std::cout << std::endl;
}
