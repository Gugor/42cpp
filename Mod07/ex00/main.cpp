#include "Whatever.hpp"
#include <iomanip>

int main (void)
{

	int a = 2;
	int b = 3;
	Whatever<int>::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Whatever<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Whatever<int>::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	Whatever<std::string>::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Whatever<std::string>::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Whatever<std::string>::max( c, d ) << std::endl;
	std::cout << std::endl;
	
	std::cout << std::fixed << std::setprecision(4);
	double da = 1441.003;
	double db = 3.141516;
	Whatever<double>::swap( da, db );
	std::cout << "da = " << da << ", db = " << db << std::endl;
	std::cout << "min( da, db ) = " << Whatever<double>::min( da, db ) << std::endl;
	std::cout << "max( da, db ) = " << Whatever<double>::max( da, db ) << std::endl;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	float fa = 1.777778f;
	float fb = 1.618033f;
	Whatever<double>::swap( da, db );
	std::cout << "fa = " << fa << ", fb = " << fb << std::endl;
	std::cout << "min( fa, fb ) = " << Whatever<double>::min( fa, fb ) << std::endl;
	std::cout << "max( fa, fb ) = " << Whatever<double>::max( fa, fb ) << std::endl;
	std::cout << std::endl;


	return (0);
}
