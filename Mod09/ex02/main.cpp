#include "PmergeMe.hpp"
#include <iostream>

int main (int ac, char * av[])
{

	if (ac < 1)
	{
		std::cerr << "ERROR: not enought arguments" << std::endl;
		exit(1);
	}

	PmergeMe app;
	PmergeMe::parseArgs(static_cast<size_t>(ac - 1), ++av);

	PmergeMe::startTimer();
	std::cout << "Before: ";
	PmergeMe::printNums("deque", PmergeMe::getDeque());
	app.sortDeque();
	std::cout << "After: ";
	PmergeMe::printNums("deque", PmergeMe::getDeque());
	PmergeMe::printTime("deque");

	PmergeMe::startTimer();
	PmergeMe::printNums("list", PmergeMe::getDeque());
	PmergeMe::printTime("list");
	return (0);
}
