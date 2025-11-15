#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "No arguments" << std::endl;
		return (0);
	}
  if (ac > 2)
  {
    std::cerr << "Error: invalid argument" << std::endl;
    std::cout << "USAGE ./rpn \"1 1 + 2 *\">" << std::endl;
    exit(0);
  }
	
	std::string str(av[1]);

	try
	{
		std::cout << setOperators(str) << std::endl;
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl;}

	return (0);
}
