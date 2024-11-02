#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bolts;	
	ClapTrap beam("Beam");	
	ClapTrap boltsV2;

	bolts = ClapTrap("Bolts");
	boltsV2 = bolts;

	bolts.attack("Bolts");
	boltsV2.takeDamage(bolts.getAttackDamage());
	std::cout << "BoltsV2 supercharges go berserker. ";
	boltsV2.setAttackDamage(8);
	boltsV2.attack("Bolts");
	bolts.takeDamage(boltsV2.getAttackDamage());
	std::cout << "BoltsV2 so quickly attacks again. ";
	boltsV2.attack("Bolts");
	bolts.takeDamage(bolts.getAttackDamage());
	beam.setAttackDamage(3);
	std::cout << "Beam takes advantage of this carnage and attacks BoltsV2 from behind" << std::endl;
	beam.attack("Bolts");
	bolts.takeDamage(beam.getAttackDamage());
	std::cout << "Surprisingly has soon has BoltsV2 take damage, it's automatic repairing systems activate. " << std::endl;
	bolts.beReapaired(1);
	std::cout << "The screen goes black for a second and then display the letters: To be continued..." << std:endl;
}
