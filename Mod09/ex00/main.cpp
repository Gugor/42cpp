#include "BitcoinExchange.hpp"
#include <iomanip>

#define DB_PATH "data.csv"
#define DB_WRONG_HEADER_PATH "data-wrong-header.csv"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	std::cout << std::fixed << std::setprecision(2) << std::endl;
	BitcoinExchange	btc(DB_PATH);
	
	try
	{
		btc.fetchEntries(std::string(av[1]));
	}
	catch (std::exception &e) { std::cerr << e.what() << std::endl;}

	return (0);
}
