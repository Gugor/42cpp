#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << numbers[4] << std::endl;
	std::cout << mirror[4] << std::endl;
	std::cout << ":: Passed out of bounds" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
	std::cout << ":: Passed out randomize" << std::endl;
    delete [] mirror;
    return 0;
}
