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
	app.mergeInsertion();
	PmergeMe::printTime("deque");
	std::cout << "After: ";
	PmergeMe::printNums("deque", PmergeMe::getDeque());
  std::cout << "Total comparissons: " << PmergeMe::_comparissons << std::endl;

  PmergeMe::_comparissons = 0;
	PmergeMe::startTimer();
	std::cout << "Before: ";
	PmergeMe::printNums("vector", PmergeMe::_vector);
	PmergeMe::printTime("vector");
	app.mergeInsertionvector();
	std::cout << "After: ";
	PmergeMe::printNums("vector", PmergeMe::_vector);
  std::cout << "Total comparissons: " << PmergeMe::_comparissons << std::endl;
	return (0);
}
