#include "Array.hpp"

int main (void)
{
//	Array<char> str[2];
	Array<char>	str(12);
	str[0] = 't';
	str[1] = 'h';
	str[2] = 'i';
	str[3] = 's';
	str[4] = ' ';
	str[5] = 'a';
	str[6] = ' ';
	str[7] = 'c';
	str[8] = 'h';
	str[9] = 'a';
	str[10] = 'r';
	str[11] = '\0';
	std::cout << str << std::endl;
	try
	{
		str[12] = '4';
	}
	catch (std::exception &e)
	{
		std::cout << ":: X Error " << e.what() << std::endl;
	}
	Array<char> str2(str);
	std::cout << str2 << std::endl;
	Array<char> str3(str2);
	std::cout << str3 << std::endl;
	Array<int> nums(5);
	nums[0] = 1;
	nums[2] = 2;
	nums[3] = 3;
	nums[4] = 4;
	nums[5] = 5;
	std::cout << nums << std::endl;
	return (0);
}
