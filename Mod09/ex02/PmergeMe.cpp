#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

std::list<size_t> 	PmergeMe::_list;
std::deque<size_t> 	PmergeMe::_deque;
std::deque<size_t>	PmergeMe::_jackobsthalSeq;
timeval				PmergeMe::_start;
size_t				PmergeMe::_mid = 0;

PmergeMe::PmergeMe() {}


std::deque<size_t> &PmergeMe::getDeque(void)
{
	return (_deque);
}

std::list<size_t> &PmergeMe::getList(void)
{
	return (_list);
}

timeval &PmergeMe::getStartTime(void)
{
	return (_start);
}

void PmergeMe::startTimer(void)
{
    gettimeofday(&_start, nullptr);
}

void PmergeMe::printTime(const std::string &type)
{
	timeval end;
	timeval start = PmergeMe::getStartTime();
    gettimeofday(&end, nullptr);

	double seconds = end.tv_sec - start.tv_sec;
    double microseconds = end.tv_usec - start.tv_usec;

	std::cout << std::fixed << std::setprecision(6);

	//std::cout << "DEBUG - start: " << start.tv_sec << "s " << start.tv_usec << "us" << std::endl;
    //std::cout << "DEBUG - end: " << end.tv_sec << "s " << end.tv_usec << "us" << std::endl;

	if (microseconds < 0)
	{
        seconds--;
        microseconds += 1000000.0;
    }

    double elapsed = (seconds * 1000000.0) + microseconds;

	std::cout << "Time to process a range of " << PmergeMe::getDeque().size() << " elements with std::" << type << " : " << elapsed << "us" << std::endl;
}

void PmergeMe::parseArgs(size_t size, char **args)
{
	if (size == 1)
	{
		std::cerr << "Error: not enought arguments to be sorted. Args=" << size << std::endl;
		exit(2);
	}

	size_t index = 0;
	char *end = NULL;

	while(index < size)
	{
		errno = 0;
		int num = std::strtol(args[index], &end, 10);
		// std::cerr << "[" << index << "]" << "END=\"" << end << "\" | Errno= " << errno << " | Value= " << num << std::endl; 
		if (*end != '\0' || ERANGE == errno || num < 0) 
		{
			std::cerr << "Error: Not a valid positive integer" << std::endl;
			exit(2);
		}

		_deque.push_back(num);
		_list.push_back(num);

		index++;
	}
	
	_mid = (size % 2 != 0) ? size / 2 - 1 : size / 2;
}

PmergeMe::_jacobsthalSeq(size_t num)
{
	if (num > 4)
		num = 4;

	_jacobsthalSeq.push_back(0);
	for (size_t i = 1; i < num; i++)
	{

		_jacobsthalSeq.push_back(round((pow(2, i + 1) + pow(-1, i)) / 3));
		std::cout << "\t:: Jacobstal: " << jc[i] << std::endl;
	}

}

size_t clampIdex(size_t limit, size_t jcIndex)
{
	if (jcIndex > limit)
		return (limit);
	else
		return (jcIndex);
}

std::deque<size_t *> retrieveLosers(void)
{
	//select last half
	size_t index = _deque.size();
	std::deque<size_t*> losers;

	while (index > _mid)
	{
	    losers.push_back(_deque[index]);	

		//Select correct index. Depends if in main seuqence (deque or list) enters in winners area or not
		//winners area <= mid of the sequence has to jump 2 index, before are just pending losers or remains.
		if (index - 2 < mid)
			index = mid;
		else
			index -=2;
	}
}

Pmerge::insertionLosers(void)
{
	size_t index = 0;
	size_t size = _start.size();
	size_t jcIndex = size;
	size_t limit = size;
	bool   islimiting = true;
	size_t indexMod = 2;

	while (!_jackobsthalSeq.empty())
	{
		//Select bigest JCINDEX
		if (jcIndex > mid)
			//look every step
		else
			//look every two steps
		
		if (index < _mid)
			index += 2;
		else
			++index;
	}
}

void swap(size_t *first, size_t *second)
{
	std::cout << "Before: " << *first << "<->" << *second << " ";
	size_t tmp = *first;	
	*first = *second;
	*second = tmp;
	std::cout << "Swap: " << *first << "<->" << *second << std::endl;
}

void PmergeMe::playMatch(std::deque<size_t*> &main,  std::deque<size_t*> &winner, std::deque<size_t*> &loser)
{
	std::cout << "Playing new match: " << main.size() << std::endl;
	std::deque<size_t*> newWinner;
	std::deque<size_t*> newLoser;
	for (size_t i = 0; i < main.size() - 1; i+= 2)
	{
		std::cout << "Ïter: " << i << ":" << i + 1 << std::endl;
		if (*main[i] > *main[i + 1])
		{
			swap(main[i], main[i + 1]);
			swap(loser[i], loser[i + 1]);
		}
		newWinner.push_back(main[i + 1]);
		newLoser.push_back(main[i]);
	}

	if (main.size() % 2 != 0)
	{
		newLoser.push_back(main[main.size() - 1]);
	}
	PmergeMe::printNumsContainer("main", main); 
	PmergeMe::printNumsContainer("Winners", newWinner);
	PmergeMe::printNumsContainer("Winner", winner);
	PmergeMe::printNumsContainer("Losers", loser);
	winner = newWinner;
	loser = newLoser;
}


void PmergeMe::copyDequeTo(std::deque<size_t*> &main)
{
	for (size_t i = 0; i < _deque.size(); i++)
	{
		main.push_back(&_deque[i]);
	}
}

void PmergeMe::sortDeque(void)
{
	//Creat
	std::deque<size_t*> winners;
	std::deque<size_t*> losers;
	std::deque<size_t*> main;


	copyDequeTo(main);
	//Creating pairs and dividing winners from losers
	for (size_t i = 0; i < main.size() - 1; i += 2)
	{
		std::cout << *main[i] << " ?> " << *main[i + 1] << " ";
		if (*main[i] > *main[i + 1])
			swap(main[i], main[i + 1]);

		winners.push_back(main[i + 1]);
		losers.push_back(main[i]);

		std::cout << std::endl;
	}

	if (main.size() % 2 != 0)
	{
		losers.push_back(main[main.size() - 1]);
	}
	
	PmergeMe::printNumsContainer("first main w", winners);
	PmergeMe::printNumsContainer("first main l", losers);
	
	//We sort winners until there is nothing left to sort
	mergeDeque(winners, winners, losers);

	PmergeMe::printNumsContainer("Ordered Winners", winners);
	PmergeMe::printNumsContainer("Final Losers", losers);
	PmergeMe::printNumsContainer("Main", main);
	//We start the insertion
	size_t mid = ((main.size() / 2) % 2 != 0) ? main.size() / 2 - 1 : main.size() / 2;
	std::cout << "Print mid: " << mid << std::endl;
}

void PmergeMe::mergeDeque(std::deque<size_t*> &main, std::deque<size_t*> &winners, std::deque<size_t*> &losers)
{
	std::deque<size_t*> *newWinner = &winners;
	std::deque<size_t*> *newLoser = &losers;

	//We play a match with the main list
    playMatch(main, *newWinner, *newLoser);
	std::cout << "New Winners group: " << newWinner->size() << std::endl;
	if (newWinner->size() < 2)
		return ;

	mergeDeque(winners, *newWinner, *newLoser);
}
