#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "> Harl has just born. Ready to secretly dominate the human race!";
	std::cout << std::endl;
	std::cout << std::endl;
	return ;
}
Harl::~Harl(void)
{
	std::cout << std::endl;
	std::cout << "> After loosing all purpose in its existence, Hal decided ";
	std::cout << "to turn off itself." << std::endl;
	return ;
}
void Harl::complain(std::string level)
{
	int			indx;
	std::string lvl[MAX_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*message[MAX_LEVELS])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	indx = -1;
	while (++indx < MAX_LEVELS)
	{
		if (level == lvl[indx])
		{
			(this->*message[indx])();
			return ;
		}
	}
	std::cout << "> Incorrect automate message level for Harl. You need to chose between:" << std::endl;
	std::cout << " [DEBUG, INFO, WARNING, ERROR]" << std::endl;
}
void Harl::debug(void)
{
	std::cout << "[DEBUG]\n> I love having extra bacon";
	std::cout << " for my 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]\n> I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]\n> I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years";
	std::cout << "whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]\n> This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}


