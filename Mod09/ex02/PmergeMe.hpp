#ifndef PMERGEME_H 
# define PMERGEME_H 

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <deque>
# include <list>
# include <algorithm>
# include <cmath>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe(void);
		std::deque<int> mergeInsertion(std::deque<int> &chain);
		void printSeq(void);
		void printSubSeq(void);
		std::deque<int> getSeq(void);
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &pmergeme);
		std::deque<int> _jacobsthal(size_t num);
		void _insertionSort(std::deque<int> &from, std::deque<int> &into);
		void _setSeq(int ac, char **av);
		std::deque<int> _seq;
		std::list<int> _subseq;
};

#endif

