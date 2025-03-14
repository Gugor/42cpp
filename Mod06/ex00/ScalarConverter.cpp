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

bool isFloat(std::string &s)
{
	char *end;

	errno = 0;
	if (s == "-inff" || s == "+inff")
		return (true);
	if (s == "nan")
		return (false);
	std::strtof(s.c_str(), &end);

	if ((s[s.size()] == 'f' && s.size() > 1 && *end == '\0') || errno == ERANGE)
		return (true);
	return (false);
}

int isInt(std::string &s)
{
	int end;
	int num = atol(s.c_str());

	end = -1;
	if (s == "-inff" || s == "+inff" || s == "nan")
		return (false);
	if (num < INT_MIN || num > INT_MAX)
		return (2);
	while (s[++end] == ' ')
		;;
	if (s[end] == '+' || s[end] == '-')
		end++;
	while(std::isdigit(s[end]))
		end++;
	if (end == static_cast<int>(s.size()))
		return (1);
	return (0);
}

int isDbl(std::string &s)
{
	char *end;

	errno = 0;
	if (s == "-inf" || s == "+inf")
		return (true);
	if (s == "nan")
		return (false);
	double dc = strtod(s.c_str(), &end);

	if ((*end != '\0' && s.size() > 1) || errno == ERANGE)
		return (0);
	return (dc);
}

int isChar(std::string &c)
{
	if (c.length() > 1 && std::isdigit(c.c_str()[0]))
		return (0);
	return (1);
}

t_types getType(std::string &s)
{
	if (isChar(s))
		return (CHART);
	if (isFloat(s))
		return (FLTT);
	if (isDbl(s))
		return (DBLT);
	if (isInt(s))
		return(INTT);
	return (IMP);
}

void ScalarConverter::convert(std::string &s)
{
	t_types type;
	char 	*end;

	errno = 0;
	end = 0;

	type = getType(s);
	std::cout << std::fixed << std::setprecision(6);

	if (type == IMP)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" <<  std::endl;
		std::cout << "double: impossible" << std::endl;
	}

	if (type == CHART)
	{
		std::cout << "Input type CHAR" << std::endl;
		std::cout << "char: '" << s.at(0) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}

	if (type == INTT)
	{
		long num = atoi(s.c_str());
			
		std::cout << "Input type INT" << std::endl;
		if (num < 32 && num > 126)
			std::cout << "char: '" << num << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(num) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(num) << std::endl;
		return ;
	}

	if (type == FLTT)
	{
		float num = std::strtof(s.c_str(), &end);

		std::cout << "Input type FLOAT" << std::endl;
		if (num < 32 && num > 126)
			std::cout << "char: '" << num << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}


	if (type == DBLT)
	{
		float num = std::strtod(s.c_str(), &end);

		std::cout << "Input type DBL" << std::endl;
		if (num < 32 && num > 126)
			std::cout << "char: '" << num << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (num < INT_MIN || num > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::strtof(s.c_str(), &end);
		if (errno == ERANGE)
			std::cout << "float: impossible" <<  std::endl;
		else
			std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}

}

