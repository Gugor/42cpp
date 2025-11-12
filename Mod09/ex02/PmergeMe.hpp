#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sys/time.h>


class PmergeMe 
{
	public:
		PmergeMe(void);

		static std::deque<size_t> &getDeque();
		static std::vector<size_t> &getvector();
		static timeval &getStartTime();
		static void	printTime(const std::string &type);

		static void parseArgs(size_t ac, char **args);
    static void printNumsPairs(std::deque< std::pair<size_t, size_t> > pairs);
		template <typename Container>
		static void printNums(const std::string &type, const Container& container);
		template <typename Container>
		static void printNumsContainer(const std::string &type, const Container &container);
    static void mergeInsertion(void);
		static void startTimer(void);
		static std::deque< std::pair<size_t, size_t> > mergedeque(std::deque< std::pair<size_t, size_t> > main);
    static std::deque< std::pair<size_t, size_t> > merge(std::deque< std::pair<size_t, size_t> > left, std::deque< std::pair<size_t, size_t> > right);
    static std::deque<size_t> dividepairs(std::deque< std::pair< size_t, size_t> >, std::deque<size_t> &losersOut);
    static void insertPending(std::deque<size_t> &losers);
    static void insertionsort(std::deque<size_t> &winners, std::deque<size_t> &losers);
    static void insertBlock(size_t from, size_t to, std::deque<size_t> &losers, std::deque<size_t> &winners);
    static void insert(size_t loser, std::deque<size_t> &winners);
    // vector
    static void printNumsPairsvector(std::vector< std::pair<size_t, size_t> > pairs);
    static void mergeInsertionvector(void);
		static std::vector< std::pair<size_t, size_t> > mergervector(std::vector< std::pair<size_t, size_t> > main);
    static std::vector< std::pair<size_t, size_t> > mergevector(std::vector< std::pair<size_t, size_t> > left, std::vector< std::pair<size_t, size_t> > right);
    static std::vector<size_t> dividepairsvector(std::vector< std::pair< size_t, size_t> >, std::vector<size_t> &losersOut);
    static void insertPendingvector(std::vector<size_t> &losers);
    static void insertionsortvector(std::vector<size_t> &winners, std::vector<size_t> &losers);
    static void insertBlockvector(size_t from, size_t to, std::vector<size_t> &losers, std::vector<size_t> &winners);
    static void insertvector(size_t loser, std::vector<size_t> &winners);




		static std::deque<size_t> _deque;
		static std::deque< std::pair <size_t, size_t> > _pending;
		static std::vector<size_t> _vector;
		static std::vector< std::pair <size_t, size_t> > _pendingvector;
    static size_t _comparissons;

	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe operator=(const PmergeMe &other);

		static void _jacobsthalSeq (const size_t num);

		static std::deque<size_t> _jcbsthlSeq;
		static timeval _start;
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
  {
      std::cout << *it << " ";  // Contenedor de valores normales
  }
	std::cout << std::endl;
}

#endif
