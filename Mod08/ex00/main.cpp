#include "easyfind.hpp"
#include <set>

#define DESIZE 5
int main (void)
{
	int nums[DESIZE] = {32,42,1,2,15};
	std::set<int> denums(nums, nums + DESIZE); 
	try
	{
		easyfind(denums, 1);
		std::cout << "Found." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(denums, 5);
		std::cout << "Found." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "." << std::endl;
	}


	return (0);
}
