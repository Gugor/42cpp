#include "Whatever.hpp"

int main (void)
{
	int a = 2;
	int b = 3;
	Whatever<int>::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Whatever<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Whatever<int>::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	Whatever<std::string>::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Whatever<std::string>::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Whatever<std::string>::max( c, d ) << std::endl;

	return (0);
}
