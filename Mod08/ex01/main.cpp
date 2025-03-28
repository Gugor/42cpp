#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main (void)
{
	{
		std::cout << "+++ Subject main +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "+++ Exception Out of Bounds main +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			sp.addNumber(11);
		}catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "+++ Exception Not enough data main +++" << std::endl;
		Span sp = Span(5);
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		Span sp2 = Span(5);
		try
		{
			sp.addNumber(6);
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

	}


	{
		std::cout << "+++ Test 10000 +++" << std::endl;
		std::srand(std::time(0));

		unsigned int size1 = 10000;
		Span sp1(size1);
		unsigned int indx = 0;

		while (++indx < size1)
		{
			sp1.addNumber(std::rand());
		}
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	/* Tarda mucho Usar con PACIENCIA 
	{
		std::srand(std::time(0));
		std::cout << "+++ Test 19000 +++" << std::endl;

		unsigned int size2 = 100000;
		Span sp2 = Span(size2);
		unsigned int indx = 0;

		while (++indx < size2)
		{
			sp2.addNumber(std::rand());
		}
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	*/

	
}
