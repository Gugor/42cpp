#include "ScalarConverter.hpp"
#include <iomanip>
#include <climits>
#include <cfloat> 
#include <cerrno> 

ScalarConverter::ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		*this = other;
	return (*this);	
}

int isChar(std::string &c)
{
	if (c.length() > 1)
		return (0);
	return (1);
}

int isOverflow(double dc, int type)
{
	if (type == INTT)
	{
		if (dc < INT_MIN || dc > INT_MAX || errno == ERANGE)
			return (1);
		return (0);
	}
	else if (type == FLTT)
	{
		if (dc < -FLT_MAX || dc > FLT_MAX || errno == ERANGE) 
			return (1);
		return (0);
	}
	else if (type == DBLT)
	{
		if (errno == ERANGE) 
			return (1);
		return (0);
	}
	else
		return (0);
}

void ScalarConverter::convert(std::string &s)
{
	char *end;
	errno = 0;
	double dc = strtod(s.c_str(), &end);
	std::cout << std::fixed << std::setprecision(6);

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
	else if (!isChar(s))
	{
		if (dc < 32 || dc > 126)
			std::cout << "char: No displayable" << std::endl;
		else
			std::cout << "char: " << static_cast<char>(dc) << std::endl;
		
		if (!isOverflow(dc, 0) && dc != 0)
			std::cout << "int: " << static_cast<int>(dc) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		if (!isOverflow(dc, 1) && dc != 0)
			std::cout << "float: " << static_cast<float>(dc) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;

		if (!isOverflow(dc, 2) && dc != 0)
			std::cout << "double: " << dc << std::endl;
		else
			std::cout << "double: impossible" << std::endl;

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

