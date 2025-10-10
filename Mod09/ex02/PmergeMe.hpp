#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <deque>
#include <list>
#include <ctime>


class PmergeMe 
{
	public:
		PmergeMe(void);

		static std::deque<size_t> &getDeque();
		static std::list<size_t> &getList();
		static timeval &getStartTime();
		static void	printTime(const std::string &type);

		static void parseArgs(size_t ac, char **args);
		template <typename Container>
		static void printNums(const std::string &type, const Container& container);
		template <typename Container>
		static void printNumsContainer(const std::string &type, const Container &container);
		static void mergeWinners(); 
		static void insertPending();
		static void startTimer(void);
		static void playMatch(std::deque<size_t*> &main,  std::deque<size_t*> &winner, std::deque<size_t*> &loser);
		static void copyDequeTo(std::deque<size_t*> &main);
		static void sortDeque(void);
		static void mergeDeque(std::deque<size_t*> &main, std::deque<size_t*> &winners, std::deque<size_t*> &losers);



	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);

		static std::deque<size_t> _deque;
		static std::list<size_t> _list;
		static size_t _jackobsthalSeq;
		static timeval _start;
		static size_t _mid;
};

template <typename Container>
void PmergeMe::printNumsContainer(const std::string &type, const Container &container)
{
	std::cout << type << ": ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << **it << " ";  // Contenedor de punteros
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printNums(const std::string &type, const Container &container)
{
	std::cout << type << ": ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";  // Contenedor de valores normales
	std::cout << std::endl;
}

#endif
