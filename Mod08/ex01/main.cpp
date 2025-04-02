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
		sp.addNumber(8);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "+++ Equal numbers +++" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(6);
		sp.addNumber(17);
		sp.addNumber(8);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "+++ Exception Out of Bounds main +++" << std::endl;
		Span sp = Span(7);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(8);
		sp.addNumber(11);
		sp.addNumber(2147483647);
		sp.addNumber(-2147483647);

		try
		{
			sp.addNumber(11);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Ranges:" << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	{
		std::cout << "+++ Exception Not enough data main +++" << std::endl;
		Span sp = Span(5);
		std::cout << "Try empty:" << std::endl;
		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Try one number:" << std::endl;
		Span sp2 = Span(5);
		try
		{
			sp.addNumber(6);
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

	}
	{
		std::cout << "+++ Test 10000 +++" << std::endl;
		std::srand(std::time(0));

		unsigned int size1 = 10000;
		Span sp1(size1);
		std::cout << "Add numbers:" << std::endl;
		try
		{
			sp1.addNumbers(0,size1);
			std::cout << "Get shortest span:" << std::endl;
			std::cout << sp1.shortestSpan() << std::endl;
			std::cout << "Get longest span:" << std::endl;
			std::cout << sp1.longestSpan() << std::endl;
		}
		catch (std::exception &e) {std::cout << e.what() << std::endl;}
	}
	/* Tarda mucho Usar con PACIENCIA 
	{
		std::srand(std::time(0));
		std::cout << "+++ Test 19000 +++" << std::endl;

		unsigned int size2 = 100000;
		Span sp2 = Span(size2);

		sp2.addNumbers(0,size2);

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	*/
}
