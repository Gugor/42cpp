#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "No arguments" << std::endl;
		return (0);
	}
	
	std::string str(av[1]);
	try
	{
		RPN	rpn(str);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl;}


	return (0);
}
