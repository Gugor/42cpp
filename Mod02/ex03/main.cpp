#include "Fixed.hpp"

int main()
{
	Fixed a;	
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl,

	std::cout << Fixed::max(a,b) << std::endl;

	std::cout << " === My tests === " << std::endl;
	std::cout << "Min between a " << a.toFloat() << " and b " << b.toFloat() << ": " << Fixed::min(a, b) << std::endl;
	std::cout << "a " << a.toFloat() << " is grater than  b " << b.toFloat() << ": " << (a > b) << std::endl;
	std::cout << "a " << a.toFloat() << " is not b " << b.toFloat() << ": " << (a != b) << std::endl;
	std::cout << "a " << a.toFloat() << " is a " << a.toFloat() << ": " << (a == a) << std::endl;
	std::cout << "a " << a.toFloat() << " is b " << b.toFloat() << ": " << (a == b) << std::endl;
	std::cout << "a " << a.toFloat() << " is grater or equals than  b " << b.toFloat() << ": " << (a >= b) << std::endl;
	std::cout << "a " << a.toFloat() << " is less or equals than  b " << b.toFloat() << ": " << (a <= b) << std::endl;
	std::cout << "a " << a.toFloat() << " is less or equals than  a " << a.toFloat() << ": " << (a <= a) << std::endl;
	return (0);
}
