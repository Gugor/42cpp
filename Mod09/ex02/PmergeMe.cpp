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


void PmergeMe::fordJhonson(std::deque<int> &input)
{
	std::deque<int> main;
	std::deque<int> pend;
	for (int i = 0; i < len / 2; i += 2)
	{	
		if (input[i] > input[i + 1])
			std::swap(input[i], input[i + 1]);

		main.push_back(input[i]);
		pend.push_back(input[i + 1]);
	}	

	mergeSort(main, 0, main.size());
	//createJacobsthal();
	//_seq = main;
	//insertSort(pend, _seq);
	//main.clear();
	//pend.clear();

}

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
	int n2 = right - mid; 

	std::deque<int> L(n1);
	std::deque<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k] = L[i];
            i++;
        }
		else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

void PmergeMe::mergeSort(std::deque<int>& seq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


