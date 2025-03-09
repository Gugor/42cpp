#include "ScalarConverter.hpp"

int main (void)
{
	std::string val = std::string("0");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("1.618034f");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("3.141592653589793238462643383279");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("nan");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("+inf");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("+inff");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("-inf");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("-inff");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("-0");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	val = std::string("42.0f");
	ScalarConverter::convert(val);
	std::cout << std::endl;

	return (0);
}
