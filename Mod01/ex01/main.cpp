#include "Zombie.hpp"
#include <cstring>
Zombie	*zombieHorde(int N, std::string name);

int main(int ac, char **av)
{
	Zombie *horde;
	if (ac == 2)
		av[2] = (char *)std::string("Rigoberto").c_str() ;
	if (ac == 1)
	{
		av[1] = (char *)std::string("5").c_str();
		av[2] = (char *)std::string("Rigoberto").c_str() ;

	}
	horde = zombieHorde(std::atoi(av[1]), av[2]);
	for(int i = 0; i < std::atoi(av[1]); ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}