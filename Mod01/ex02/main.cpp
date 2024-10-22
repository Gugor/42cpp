#include <iostream>
#include <string>

int main(void)
{
	std::string *stringPTR;
	std::string msg 		= "HI THIS IS BRAIN";
	std::string &stringREF	= msg;
	stringPTR 				= &msg;
	std::cout << "string: " << &msg << std::endl;
	std::cout << "PTR: " << &stringPTR << std::endl;
	std::cout << "REF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "string: " << msg << std::endl;
	std::cout << "PTR: " << stringPTR << std::endl;
	std::cout << "REF: " << stringREF << std::endl;
}