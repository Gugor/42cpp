#include "PmergeMe.hpp"

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		exit(1);
	}
	
	try
	{
		av++;
		PmergeMe	pmergeme(ac - 1, av);
		std::deque<int> seq = pmergeme.getSeq();
		std::deque<int>::iterator end = seq.end();
		pmergeme.mergeSort(seq, end, seq.size());
	}
	catch(std::exception &e) {std::cerr << e.what() << std::endl;}

	return (0);
}
