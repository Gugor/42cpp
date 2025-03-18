#include "Whatever.hpp"
#include <iomanip>

int main (void)
{

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	
	std::cout << std::fixed << std::setprecision(4);
	double da = 1441.003;
	double db = 3.141516;
	::swap( da, db );
	std::cout << "da = " << da << ", db = " << db << std::endl;
	std::cout << "min( da, db ) = " << ::min( da, db ) << std::endl;
	std::cout << "max( da, db ) = " << ::max( da, db ) << std::endl;
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(6);
	float fa = 1.777778f;
	float fb = 1.618033f;
	::swap( fa, fb );
	std::cout << "fa = " << fa << ", fb = " << fb << std::endl;
	std::cout << "min( fa, fb ) = " << ::min( fa, fb ) << std::endl;
	std::cout << "max( fa, fb ) = " << ::max( fa, fb ) << std::endl;
	std::cout << std::endl;

	return (0);
}
