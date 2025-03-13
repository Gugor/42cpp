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

int isFloat(std::string &s)
{
	char *end;

	errno = 0;
	float fc = strtof(s.c_str(), &end);

	if ((s[s.size()] == 'f' && s.size() > 1 && *end == '\0') || errno == ERANGE)
		return (fc);
	return (0);
}

int isInt(std::string &s)
{
	int end;
	int num = atol(s.c_str());

	end = -1;
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
	double dc = strtod(s.c_str(), &end);

	if ((*end != '\0' && s.size() > 1) || errno == ERANGE)
		return (0);
	return (dc);
}

int isChar(std::string &c)
{
	if (c < 32 || c > 126)
		return (2);
	if (c.length() > 1)
		return (0);
	return (1);
}

t_types getType(std::string &s, int *res)
{
	if (*res = isChar(s))
		return (CHART);
	else if (*res = isFloat(s))
		return (FLTT);
	else if (*res = isDbl(s))
		return (DBLT);
	else if (*res = isInt(s))
		return(INTT);
	else
		return (IMP);
}

void toChar(std::string &s, t_type from, void *data)
{
	if (from == IMP)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (from == CHART)
	{
		std::cout << "char: '" << s.at(0) << "'" << std::endl;
		return ;
	}
	if (from == INTT)
	{
		int num = *data;
		std::cout << "char: '" << s << "'" << std::endl;
		return ;
	}
	if (from == FLTT)
	if (from == DBLT)
}

void ScalarConverter::convert(std::string &s)
{
	t_types type;
	int	res;

	errno = 0;

	type = getType(s, &res);
	std::cout << std::fixed << std::setprecision(6);

	if (type == IMP)
	{
		std::cout << "Input type STRING" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" <<  std::endl;
		std::cout << "double: impossible"  << std::endl;
		return ;
	}

	if (type == CHART)
	{
		std::cout << "Input type CHAR" << std::endl;
		std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}

	if (type == INTT)
	{
		long num = atoi(s.c_str());
		if (num < INT_MIN || num > INT_MAX)
			
		std::cout << "Input type INT" << std::endl;
		std::cout << "int: " << static_cast<int>(ic) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}

	if (type == FLTT)
	{
		std::cout << "Input type FLOAT" << std::endl;
		std::cout << "char: '" << s << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}


	if (type == DBLT)
	{
		std::cout << "Input type DBL" << std::endl;
		std::cout << "char: '" << s << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(s.at(0)) << "f" <<  std::endl;
		std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
		return ;
	}

}

