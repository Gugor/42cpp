#include "BitcoinExange.hpp"
#include <iomanip>

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::cout << std::fixed << std::setprecision(2) << std::endl;
	BitcoinExange	bitcoinexange((std::string(av[1])));
	
	try
	{
		bitcoinexange.fetchEntries("input.txt");
		//bitcoinexange.fetchDB("data.csv");
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl;}

	bitcoinexange.printEntries();
	//bitcoinexange.printDB();
	return (0);
}
