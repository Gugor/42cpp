#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
		return (0);
        if (std::string(av[1]).empty() || ac > 2)
		return (0);
	std::string val = std::string("0");
	val = std::string(av[1]);
	ScalarConverter::convert(val);
	return (0);
}
