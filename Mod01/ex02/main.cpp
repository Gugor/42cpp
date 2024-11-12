#include <iostream>
#include <string>

int main(void)
{
	std::string msg 	= "HI THIS IS BRAIN";
	std::string *stringPTR;
	stringPTR 		= &msg;
	std::string &stringREF	= msg;

	std::cout << "string ref: " << &msg << std::endl;
	std::cout << "string cont: " << msg << std::endl;

	std::cout << std::endl;

	std::cout << "PTR by ref: " << &stringPTR << std::endl;
	std::cout << "REF by ref: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "PTR by content: " << stringPTR << std::endl;
	std::cout << "REF by content: " << stringREF << std::endl;
}
