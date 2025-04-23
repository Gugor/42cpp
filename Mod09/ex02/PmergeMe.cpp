#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	this->_setSeq(ac, av);
}

PmergeMe::~PmergeMe(void){}

std::deque<int> PmergeMe::getSeq(void)
{
	return (this->_seq);
}

bool isInteger(char *str)
{
	char *endptr = NULL;
	long num = 0;

	errno = 0;
	num = std::strtol(str, &endptr, 10);	
	if (*endptr != '\0' || errno != 0 || num < 0 || num > INT_MAX)
		return (false);
	return (true);
}

void PmergeMe::_setSeq(int ac, char **av)
{
	int indx = -1;
	while (++indx < ac)
	{
		if(!isInteger(av[indx]))
			throw std::invalid_argument("Error: not valid integer");
		this->_seq.push_back(atoi(av[indx]));
	}
	std::cout << "Before: ";
	this->printSeq();
}

void PmergeMe::printSeq(void)
{
	std::deque<int>::iterator begin = this->_seq.begin();
	std::deque<int>::iterator end = this->_seq.end();
	
	while(begin != end)
	{
		const char *sp = ((begin + 1) == end) ? "" : " ";
		std::cout << (*begin) << sp ; 
		begin++;
	}
	std::cout << std::endl;
}

void PmergeMe::printSubSeq(void)
{
	std::list<int>::iterator begin = this->_subseq.begin();
	std::list<int>::iterator end = this->_subseq.end();
	
	while(begin != end)
	{
		const char *sp = ((std::next(this->_subseq.begin())) == this->_subseq.end()) ? "" : " ";
		std::cout << (*begin) << sp ; 
		begin++;
	}
	std::cout << std::endl;
}

size_t PmergeMe::jacobsthal(size_t num)
{
	return (round((pow(2, num + 1) + pow(-1, num)) / 3));
}



std::deque<int> mergeInsertion(std::deque<int> &chain)
{
	if (chain.size() <= 1)
		return (chain);

	std::deque<int>::iterator begin = chain.begin();
	std::deque<int>::iterator end = chain.end();

	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int> leftover;

	//We obtain left over in case chain is odd
	if (chain.size() % 2 == 1)
		leftover.insert(chain.end() - 1);

	//We get main chain filled with bigest numbers from pairs
	while (begin < end)
	{
		if ((*begin) >= (*begin + 1))
		{
			main.insert(begin);	
			pend.insert((begin + 1));
		}
		else
		{
			main.insert((begin + 1));	
			pend.insert(begin);
		}
		begin += 2;
	}
	chain.clear();

	//We check main is still a pair and insert pend into it if needed
	/*if (main.size() <= 1)
	{
		main = this->_insertionSearch(pend, main);
		return (main);
	}*/

	//If still numbers in main we restart the process
	this->mergeInsertion(main);
	//When no more to sort in main we insert leftover and pend
	main = this->insertionSearch(leftover, main);
	main = this->insertionSearch(pend, main);

	return (main);
}

