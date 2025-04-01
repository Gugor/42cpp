#include "Span.hpp"

Span::Span(void){}

Span::Span(const unsigned int n)
{
	this->_n = n;
}

Span::Span(const Span &other)
{
	if (this != &other)
	{
		this->_n = other.getN();
	}
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other.getN();
	}
	return (*this);
}

Span::~Span(void){}

void Span::addNumber(int num)
{
	if (this->_span.size() >= this->_n)
		throw std::out_of_range("Out of bounds: there is no more space to add a number.");
	this->_span.push_back(num);
}

unsigned int  Span::getN(void) const
{
	return (this->_n);
}

long Span::shortestSpan(void)
{
	std::vector<int>::iterator begin = this->_span.begin();
	std::vector<int>::iterator end = this->_span.end();
	std::vector<int>::iterator indx = begin;

	if (this->_span.empty() || this->_span.size() < 2)
		throw std::exception();

	indx = begin;
	long dist = std::abs(*begin - *(++indx));
	while (++begin != end)
	{
		indx = begin;
		while (++indx != end)
		{
			if (dist > std::abs(*indx - *begin))
				dist = std::abs(*indx - *begin); 
		}
	}
	return (dist);
}

void Span::addNumbers(unsigned int start, unsigned int end)
{

	if (start > end)
		throw std::out_of_range("Out of bounds: end can't be smaller than start.");
	unsigned int indx = 0;
	unsigned int range = end - start;

	while (indx < range)
	{
		try
		{
			this->addNumber(std::rand());
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << ": Impossible to add more numbers." << std::endl;
		}
		indx++;
	}
}

long Span::longestSpan(void)
{
	long dist = 0;
	std::vector<int>::iterator begin = this->_span.begin();
	std::vector<int>::iterator end = this->_span.end();
	std::vector<int>::iterator indx = begin;

	if (this->_span.empty() || this->_span.size() < 2)
		throw std::exception();

	while (begin != end)
	{
		indx = begin;
		while (indx != end)
		{
			if (dist < std::abs(static_cast<long>(*indx) - static_cast<long>(*begin)))
				dist = std::abs(static_cast<long>(*indx) - static_cast<long>(*begin)); 
			indx++;
		}
		begin++;
	}
	return (dist);
}
