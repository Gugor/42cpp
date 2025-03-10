#include "ScalarConverter.hpp"
#include <iomanip>


int isChar(std::string &c)
{
	if (c.length() > 1)
		return (0);
	return (1);
}

void ScalarConverter::convert(std::string &s)
{
//	char *end;
//	end = 0;
	double dc = atof(s.c_str());
	std::cout << std::fixed << std::setprecision(6);
	std::cout << dc << std::endl;	

	if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nan" << std::endl;
		std::cout << "double: nanf" << std::endl;
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inf" << std::endl;
		std::cout << "double: +inff" << std::endl;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inf" << std::endl;
		std::cout << "double: -inff" << std::endl;
	}
	else if (s.length() > 1)
	{
		if (dc < 32 || dc > 126)
			std::cout << "char: No displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(dc) << std::endl;
		std::cout << "int: " << static_cast<int>(dc) << std::endl;
		std::cout << "float: " << static_cast<float>(dc) << "f" << std::endl;
		std::cout << "double: " << dc << std::endl;
	}
	else if (isChar(s))
	{
		if (isChar(s) && s.at(0) < 32 && s.at(0) > 126)
			std::cout << "char: No displayable " << std::endl;
		else	
			std::cout << "char: " << static_cast<char>(s.at(0)) << std::endl;
		std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) <<  std::endl;
	}
}

