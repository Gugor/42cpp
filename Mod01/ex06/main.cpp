#include "Harl.hpp"

enum e_levels
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
}; 

int getLevelint(std::string level)
{
	std::string lvl[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (level == lvl[0])
		return (0);
	if (level == lvl[1])
		return (1);
	if (level == lvl[2])
		return (2);
	if (level == lvl[3])
		return (3);
	return (-1);
}

int main(int ac, char **av)
{
	std::string	level;	
	Harl		harl;

	if (ac != 2)
		level = "DEBUG";
	else
		level = std::string(av[1]);
	switch (getLevelint(level))
	{
		case DEBUG:		harl.complain("DEBUG");
		case INFO:		harl.complain("INFO");
		case WARNING:	harl.complain("WARNING");
		case ERROR:		harl.complain("ERROR");
			break;
		default:		harl.complain("");
			break;
	}
	return (0);
}