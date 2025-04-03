#include "BitcoinExange.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
	}
	BitcoinExange	bitcoinexange((std::string(av[1])));
	
	bitcoinexange.fetchEntries("input.txt");
	return (0);
}
