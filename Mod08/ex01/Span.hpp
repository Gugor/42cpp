#ifndef SPAN_H 
# define SPAN_H 

# include <iostream>
# include <set>
# include <cmath>

class Span
{
	public:
		Span(void);
		Span(const unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &span);
		~Span(void);
		unsigned int  getN(void) const; 
		void addNumber(int num); 
		long shortestSpan(void);
		long longestSpan(void);
	private:
		unsigned int _n;
		std::set<long> _span;

};

#endif

