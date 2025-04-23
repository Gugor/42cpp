#ifndef PMERGEME_H 
# define PMERGEME_H 

# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <deque>
# include <list>
# include <algorithm>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **av);
		~PmergeMe(void);
		void mergeSort(std::deque<int> &nums, int left, int right);
		std::deque<int> mergeInsertion(std::deque<int> &chain);
		void fordJhonson(std::deque<int> &input);
		void printSeq(void);
		void printSubSeq(void);
		std::deque<int> getSeq(void);
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &pmergeme);
		void _setSeq(int ac, char **av);
		std::deque<int> _seq;
		std::list<int> _subseq;
};

#endif

