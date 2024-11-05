#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap lights;	
	ScavTrap beam("Boom");	
	ScavTrap lightsV2;
	std::cout << std::endl;
	lights = ClapTrap("Lights");
	lightsV2 = lights;
	std::cout << std::endl;

	lights.attack("Lights");
	lightsV2.takeDamage(lights.getAttackDamage());
	std::cout << "> LightsV2 supercharges go berserker. ";
	lightsV2.setAttackDamage(8);
	lightsV2.attack("Lights");
	lights.takeDamage(lightsV2.getAttackDamage());
	lights.getHitPoints();
	std::cout << "> LightsV2 so quickly attacks again. ";
	lightsV2.attack("Lights");
	lights.takeDamage(lightsV2.getAttackDamage());
	lights.getHitPoints();
	beam.setAttackDamage(3);
	std::cout << "> Boom takes advantage of this carnage and attacks LightsV2 from behind" << std::endl;
	beam.attack("Lights");
	lights.takeDamage(beam.getAttackDamage());
	std::cout << "> Surprisingly has soon has LightsV2 take damage, it's automatic repairing systems activate. " << std::endl;
	lights.beRepaired(1);
	std::cout << "> The screen goes black for a second and then display the letters: To be continued..." << std::endl;
	std::cout << std::endl;
}
