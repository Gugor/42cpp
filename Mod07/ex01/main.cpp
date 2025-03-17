#include "Iter.hpp"
#include <iomanip>

int main (void)
{

	std::cout << std::fixed << std::setprecision(3);
	std::string str = std::string("i want to grow!");
	int iarr[5] = {1,2,3,4,5};
	float farr[5] = {1.0f,2.0f,3.0f,4.0f,5.0f};
	double darr[5] = {1.1,2.2,3.3,4.4,5.5};
	
	iter(str.c_str(), (size_t)14, printTemp);
	std::cout << std::endl;
	iter(str.c_str(), (size_t)14, toupper);
	std::cout << std::endl;
	iter(iarr, (size_t)5, printTemp);
	std::cout << std::endl;
	iter(farr, (size_t)5, printTemp);
	std::cout << std::endl;
	iter(darr, (size_t)5, printTemp);
	std::cout << std::endl;
	return (0);
}
