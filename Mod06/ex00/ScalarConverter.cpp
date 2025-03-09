#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string &s)
{
	double dc = atof(s.c_str());

	if (s.length() > 1 && dc != 0)
	{
		if (dc < 32 || dc > 126)
			std::cout << "char: No displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(dc) << std::endl;
	}
	else if (s.length() > 1 && dc == 0)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
		std::cout << "char: " << static_cast<char>(s.at(0)) << std::endl;

	if (s == "nan" || s == "nanf")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nan" << std::endl;
		std::cout << "double: nanf" << std::endl;
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inf" << std::endl;
		std::cout << "double: +infff" << std::endl;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inf" << std::endl;
		std::cout << "double: -inff" << std::endl;
	}
	else
	{
		std::cout << "int: " << static_cast<int>(dc) << std::endl;
		std::cout << "float: " << static_cast<float>(dc) << std::endl;
		std::cout << "double: " << dc << std::endl;
	}
}

