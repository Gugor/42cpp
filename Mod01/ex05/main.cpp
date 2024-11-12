#include "Harl.hpp"

int main(int ac, char **av)
{
	std::string	level;	
	Harl		harl;

	if (ac != 2)
		level = "DEBUG";
	else
		level = std::string(av[1]);
	std::cout << std::endl;
	harl.complain(level);	
	return (0);
}
