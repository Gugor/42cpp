#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av)
{
	this->_setSeq(ac, av);
	this->_seq = this->mergeInsertion(this->_seq);
	std::cout << "After: ";
	this->printSeq();
	std::cout << std::endl;
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

std::deque<int> PmergeMe::_jacobsthal(size_t num)
{
	std::deque<int> jc;

	for (size_t i = 0; i < num; i++)
	{

		jc.push_back(round((pow(2, i + 1) + pow(-1, i)) / 3));
		std::cout << "Jacobstal: " << jc[i] << std::endl;
	}

	return (jc);
}

void PmergeMe::_insertionSort(std::deque<int> &from, std::deque<int> &into)
{
	std::cout << "Insertion " << std::endl;
	if (from.size() <= 0)
		return ;

	std::cout << "From size:  " << from.size() << std::endl;
	std::deque<int> jc = this->_jacobsthal(from.size());
	std::cout << "Jc size: " << jc.size() << std::endl;
	size_t indx = from.size();

	while (indx > 0)
	{
		std::deque<int>::iterator begin = into.begin();
		std::deque<int>::iterator end = into.end();

		while (begin != end)
		{
			std::cout << "Jc extraction: " << jc[indx] << std::endl;
			std::cout << "From extraction: " << from[jc[indx]] << std::endl;
			if (from[jc[--indx]] < (*begin))
			{
				into.insert(begin, from[jc[indx]]);
				begin++;
				break;
			}
			begin++;
		}
	}
	from.clear();
}

std::deque<int> PmergeMe::mergeInsertion(std::deque<int> &chain)
{
	std::cout << "Seq size: " << chain.size() << "|" << chain[0] << std::endl;
	if (chain.size() <= 1)
		return (chain);

	static int lvl = 0;
	std::deque<int>::iterator begin = chain.begin();
	std::deque<int>::iterator end = chain.end();

	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int> leftover;

	std::cout << "Level " << lvl << std::endl;
	//We obtain left over in case chain is odd
	if (chain.size() % 2 == 1)
		leftover.push_back((*(end - 1)));

	//We get main chain filled with bigest numbers from pairs
	for (int dist = chain.size() / 2; dist > 0; dist--)
	{
		std::cout << "Dist " << dist << "Pairs: " << (*begin) << "|" << (*(begin + 1)) << std::endl;
		if ((*begin) >= (*(begin + 1)))
		{
			main.push_back(*begin);	
			pend.push_back((*(begin + 1)));
		}
		else
		{
			main.push_back((*(begin + 1)));	
			pend.push_back(*begin);
		}
		begin += 2;
		dist = end - begin;
	}
	chain.clear();

	//If still numbers in main we restart the process
	lvl++;
	main = this->mergeInsertion(main);
	for (size_t i = 0; i < main.size(); i++)
		std::cout << "Main bi: " << main[i] << std::endl;
	//When no more to sort in main we insert leftover and pend
	/*if (!leftover.empty())
	{
		std::cout << "Left over: " << leftover.size() << "|" << leftover[0] << std::endl;
		this->_insertionSort(leftover, main);
	}a*/
	std::cout << "Main size: " << main.size() << "|" << main[0] << std::endl;
	std::cout << "Pena : " << pend.size() << "|" << pend[0] << std::endl;
	this->_insertionSort(pend, main);

	return (main);
}

