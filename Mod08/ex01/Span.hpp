#ifndef SPAN_H 
# define SPAN_H 

# include <iostream>
# include <vector>
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
		void addNumbers(unsigned int start, unsigned int end); 
		long shortestSpan(void);
		long longestSpan(void);
	private:
		unsigned int _n;
		std::vector<int> _span;

};

#endif

