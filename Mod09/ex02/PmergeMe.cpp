#include "PmergeMe.hpp"
#include <iomanip>
#include <complex>
#include <cerrno>  // for errno and ERANGE



std::deque<size_t> PmergeMe::_deque;
std::deque< std::pair< size_t, size_t> > PmergeMe::_pending;
std::vector<size_t> PmergeMe::_vector;
std::vector< std::pair< size_t, size_t> > PmergeMe::_pendingvector;
std::deque<size_t> PmergeMe::_jcbsthlSeq;
size_t PmergeMe::_comparissons = 0;
timeval PmergeMe::_start;


PmergeMe::PmergeMe() {}

std::deque<size_t> &PmergeMe::getDeque(void)
{
	return (_deque);
}

std::vector<size_t> &PmergeMe::getvector(void)
{
	return (_vector);
}

timeval &PmergeMe::getStartTime(void)
{
	return (_start);
}

void PmergeMe::startTimer(void)
{
     gettimeofday(&_start, NULL);
}

void PmergeMe::printTime(const std::string &type)
{
	timeval end;
	timeval start = PmergeMe::getStartTime();
  gettimeofday(&end, NULL);

	double seconds = end.tv_sec - start.tv_sec;
  double microseconds = end.tv_usec - start.tv_usec;

	std::cout << std::fixed << std::setprecision(6);

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
    if (std::find(_deque.begin(), _deque.end(), num) == _deque.end())
    {
        _deque.push_back(num);
        _vector.push_back(num);
    }
		index++;
	}
	
}

void PmergeMe::_jacobsthalSeq(const size_t num)
{
  size_t jc = 0;
	_jcbsthlSeq.push_back(0);
  // std::cout << "Jacobsthal Seq: " ;
	for (size_t i = 1; i < num; i++)
  {
   jc = round((pow(2, i + 1) + pow(-1, i)) / 3) - 1; 
   if (jc > num)
   {
     jc = num - 1;
		_jcbsthlSeq.push_back(jc);
    // std::cout << _jcbsthlSeq[i] << " ";
    break;
   }
		_jcbsthlSeq.push_back(jc);
    // std::cout << _jcbsthlSeq[i] << " ";
  }
  // std::cout << std::endl;
}

std::deque< std::pair<size_t, size_t> > makePairs()
{
  std::deque< std::pair<size_t, size_t> > pairs;
  std::deque<size_t> &dq = PmergeMe::_deque;
  for (size_t indx = 0; indx < dq.size() - 1; indx += 2)
  {
      if (dq[indx] < dq[indx + 1])
      {
          pairs.push_back(std::pair<size_t, size_t>(dq[indx], dq[indx + 1]));
      }
      else
      {
          pairs.push_back(std::pair<size_t, size_t>(dq[indx + 1], dq[indx])); 
      }
  }
  return (pairs);
}

std::deque< std::pair<size_t, size_t> > PmergeMe::merge(std::deque< std::pair<size_t, size_t> > left, std::deque< std::pair<size_t, size_t> > right)
{
  std::deque< std::pair<size_t, size_t> > sorted; 

  // Sort until left or right empty, or both
  while (!left.empty() && !right.empty())
  {
      if (left[0].second < right[0].second)
      {
        sorted.push_back(left[0]);   
        left.pop_front();
        _comparissons++;
      }
      else
      {
        sorted.push_back(right[0]);
        right.pop_front();
        _comparissons++;
      }
  }

  // In case LEFT has more data we sort it out
  while (!left.empty())
  {
    sorted.push_back(left[0]);   
    left.pop_front();
  }

  // In case RIGHT has more data we sort it out
  while (!right.empty())
  {
    sorted.push_back(right[0]);
    right.pop_front();
  }
  return(sorted);
}

void PmergeMe::printNumsPairs(std::deque< std::pair<size_t, size_t> > pairs)
{
  std::cout << "    Winners: ";
  for (size_t indx = 0; indx < pairs.size(); indx++)
    std::cout << pairs[indx].second << " ";
  std::cout << std::endl;
  std::cout << "    Losers: ";
  for (size_t indx = 0; indx < pairs.size(); indx++)
    std::cout << pairs[indx].first << " ";
  std::cout << std::endl;
}

std::deque< std::pair<size_t, size_t> > PmergeMe::mergedeque(std::deque< std::pair<size_t, size_t> > main)
{
  if (main.size() < 2) 
    return (main);

  static size_t lvl = 0;
  lvl++;
  size_t mid = main.size() / 2;
  std::deque< std::pair<size_t, size_t> > pend;

  if (main.size() % 2 != 0)
  {
    _pending.push_back(main[main.size() - 1]);
    main.pop_back();
  }
  std::deque< std::pair<size_t, size_t> > left (main.begin(), main.end() - mid);
  std::deque< std::pair<size_t, size_t> > right(main.begin() + mid, main.end());

  /*
  std::cout << "LVL: " << lvl << " | Size: " << main.size() << " | Mid: " << mid << "\n";
  std::cout << "Left: \n";
  printNumsPairs(left);
  std::cout << "Right: \n";
  printNumsPairs(right);
  std::cout << "Pending: \n";
  printNumsPairs(_pending);
  */
  std::deque< std::pair<size_t, size_t> > newleft = mergedeque(left);
  std::deque< std::pair< size_t, size_t> > newright = mergedeque(right);

  std::deque< std::pair<size_t, size_t> > sorted = merge(newleft, newright);
  // std::cout << "Sorted: \n";
  // printNumsPairs(sorted);
  return (sorted);
}

std::deque<size_t> PmergeMe::dividepairs(std::deque< std::pair< size_t, size_t> > pairs, std::deque<size_t> &losersOut)
{
  std::deque<size_t> winners;

  for(size_t indx = 0; indx < pairs.size(); indx++) 
  {
    winners.push_back(pairs[indx].second);
    losersOut.push_back(pairs[indx].first);
    _comparissons++;
  }
  return (winners);
}

void PmergeMe::insertPending(std::deque<size_t> &losers)
{
  while (!_pending.empty())
  {
    losers.push_back(_pending[0].first);
    losers.push_back(_pending[0].second);
    _pending.pop_front();
  }
}


void PmergeMe::insert(size_t loser, std::deque<size_t> &winners)
{
  //std::cout << "  Loser > Winners: " << ( loser > winners[0] ) << " l:" << loser << " | w:" << winners[0] << "\n";
  size_t indx = 0;
  for (; indx < winners.size() && loser > winners[indx]; indx++)
  {
    //std::cout << "  [" << indx <<  "] Loser > Winners: " << ( loser > winners[indx] ) << " l:" << loser << " | w:" << winners[indx] << "\n";
  }
    std::deque<size_t>::iterator it = winners.begin() + indx;
    winners.insert(it, loser);
    //printNums("Winners after insetion: ", winners);
}

void PmergeMe::insertBlock(size_t from, size_t to, std::deque<size_t> &losers, std::deque<size_t> &winners)
{
  if (losers.empty())
    return ;
  if (from >= losers.size())
    from = losers.size() - 1;
  while (from > to)
  {
      insert(losers[from], winners);
      from--;
  }
}

void PmergeMe::insertionsort(std::deque<size_t> &winners, std::deque<size_t> &losers)
{
  std::deque<size_t> final;
  size_t jcto = 0;
  size_t jcfrom = 0;
  //insert first in sequence
  winners.push_front(losers[0]);
  losers.pop_front();
  // printNums(" First loser inserted L:", losers);
  // printNums(" First loser inserted W:", winners);
  for (size_t jcindx = 0; jcindx < _jcbsthlSeq.size(); jcindx++)
  {
    //getjcIndex Value
    jcfrom = _jcbsthlSeq[jcindx];
    insertBlock(jcfrom, jcto, losers, winners);
    jcto = _jcbsthlSeq[jcindx]; 
  }
}

void PmergeMe::mergeInsertion(void)
{
  //create pairs
  std::deque< std::pair<size_t, size_t> > pairs = makePairs();

  //mergedeque
  std::deque< std::pair< size_t, size_t> > winsorted = mergedeque(pairs);
  //insertPending
  //divide pairs
  std::deque<size_t> losersOut;
  std::deque<size_t> winners = dividepairs(winsorted, losersOut);
  insertPending(losersOut);
  _jacobsthalSeq(losersOut.size());
  // printNums("Winners:",winners);
  // printNums("Losers:", losersOut);
  insertionsort(winners, losersOut);
  _deque = winners;
}


/****************************************************
 * vector Code
****************************************************/

std::vector< std::pair<size_t, size_t> > makePairsvector()
{
  std::vector< std::pair<size_t, size_t> > pairs;
  std::vector<size_t> &dq = PmergeMe::_vector;
  for (size_t indx = 0; indx < dq.size() - 1; indx += 2)
  {
      if (dq[indx] < dq[indx + 1])
      {
          pairs.insert(pairs.end(), std::pair<size_t, size_t>(dq[indx], dq[indx + 1]));
      }
      else
      {
          pairs.insert(pairs.end(), std::pair<size_t, size_t>(dq[indx + 1], dq[indx])); 
      }
  }
  return (pairs);
}


std::vector< std::pair<size_t, size_t> > PmergeMe::mergevector(std::vector< std::pair<size_t, size_t> > left, std::vector< std::pair<size_t, size_t> > right)
{
    std::vector<std::pair<size_t, size_t> > sorted; 
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i].second < right[j].second)
            sorted.push_back(left[i++]);
        else
            sorted.push_back(right[j++]);
        _comparissons++;
    }

    // Agrega los restantes
    while (i < left.size()) sorted.push_back(left[i++]);
    while (j < right.size()) sorted.push_back(right[j++]);

    return sorted;
}

void PmergeMe::printNumsPairsvector(std::vector< std::pair<size_t, size_t> > pairs)
{
   std::cout << "    Winners: ";
  for (size_t indx = 0; indx < pairs.size(); indx++)
    std::cout << pairs[indx].second << " ";
  std::cout << std::endl;
  std::cout << "    Losers: ";
  for (size_t indx = 0; indx < pairs.size(); indx++)
    std::cout << pairs[indx].first << " ";
  std::cout << std::endl;
}

std::vector< std::pair<size_t, size_t> > PmergeMe::mergervector(std::vector< std::pair<size_t, size_t> > main)
{
  if (main.size() < 2) 
    return (main);

  static size_t lvl = 0;
  lvl++;
  size_t mid = main.size() / 2;
  std::vector< std::pair<size_t, size_t> > pend;

  if (main.size() % 2 != 0)
  {
    _pendingvector.push_back(main[main.size() - 1]);
    main.pop_back();
  }
  std::vector< std::pair<size_t, size_t> > left (main.begin(), main.end() - mid);
  std::vector< std::pair<size_t, size_t> > right(main.begin() + mid, main.end());

  /*
  std::cout << "LVL: " << lvl << " | Size: " << main.size() << " | Mid: " << mid << "\n";
  std::cout << "Left: \n";
  printNumsPairsvector(left);
  std::cout << "Right: \n";
  printNumsPairsvector(right);
  std::cout << "Pending: \n";
  printNumsPairsvector(_pendingvector);
*/
  std::vector< std::pair<size_t, size_t> > newleft = mergervector(left);
  std::vector< std::pair< size_t, size_t> > newright = mergervector(right);

  std::vector< std::pair<size_t, size_t> > sorted = mergevector(newleft, newright);
  // std::cout << "Sorted: \n";
  // printNumsPairsvector(sorted);
  return (sorted);
}

std::vector<size_t> PmergeMe::dividepairsvector(std::vector< std::pair< size_t, size_t> > pairs, std::vector<size_t> &losersOut)
{
  std::vector<size_t> winners;

  for(size_t indx = 0; indx < pairs.size(); indx++) 
  {
    winners.push_back(pairs[indx].second);
    losersOut.push_back(pairs[indx].first);
    _comparissons++;
  }
  return (winners);
}

void PmergeMe::insertPendingvector(std::vector<size_t> &losers)
{
  while (!_pendingvector.empty())
  {
    losers.push_back(_pendingvector[0].first);
    losers.push_back(_pendingvector[0].second);
    _pendingvector.erase(_pendingvector.begin());
  }
}


void PmergeMe::insertvector(size_t loser, std::vector<size_t> &winners)
{
  // std::cout << "  Loser > Winners: " << ( loser > winners[0] ) << " l:" << loser << " | w:" << winners[0] << "\n";
  size_t indx = 0;
  for (; indx < winners.size() && loser > winners[indx]; indx++)
  {
    // std::cout << "  [" << indx <<  "] Loser > Winners: " << ( loser > winners[indx] ) << " l:" << loser << " | w:" << winners[indx] << "\n";
  }

    std::vector<size_t>::iterator it = winners.begin() + indx;
    winners.insert(it, loser);
  // printNums("Winners after insetion: ", winners);
}

void PmergeMe::insertBlockvector(size_t from, size_t to, std::vector<size_t> &losers, std::vector<size_t> &winners)
{
  if (losers.empty())
    return ;
  if (from >= losers.size())
    from = losers.size() - 1;
  while (from > to)
  {
      insertvector(losers[from], winners);
      from--;
  }
}

void PmergeMe::insertionsortvector(std::vector<size_t> &winners, std::vector<size_t> &losers)
{
  std::vector<size_t> final;
  size_t jcto = 0;
  size_t jcfrom = 0;
  //insert first in sequence
  winners.insert(winners.begin(), losers[0]);
  losers.erase(losers.begin());
  // printNums(" First loser inserted L:", losers);
  // printNums(" First loser inserted W:", winners);
  for (size_t jcindx = 0; jcindx < _jcbsthlSeq.size(); jcindx++)
  {
    //getjcIndex Value
    jcfrom = _jcbsthlSeq[jcindx];
    insertBlockvector(jcfrom, jcto, losers, winners);
    jcto = _jcbsthlSeq[jcindx]; 
  }
}

void PmergeMe::mergeInsertionvector(void)
{
  //create pairs
  std::vector< std::pair<size_t, size_t> > pairs = makePairsvector();

  //mergedeque
  std::vector< std::pair< size_t, size_t> > winsorted = mergervector(pairs);
  //insertPending
  //divide pairs
  std::vector<size_t> losersOut;
  std::vector<size_t> winners = dividepairsvector(winsorted, losersOut);
  insertPendingvector(losersOut);
  _jcbsthlSeq.clear();
  _jacobsthalSeq(losersOut.size());
  // printNums("Winners:",winners);
  // printNums("Losers:", losersOut);
  insertionsortvector(winners, losersOut);
  _vector = winners;
}
