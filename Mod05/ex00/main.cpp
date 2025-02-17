
#include "Bureaucrat.hpp"

int main(void)
{	
	{
		Bureaucrat An;
		Bureaucrat Steve("Steve", 1);
		Bureaucrat SteveCpy;
		SteveCpy = Steve;

		std::cout << std::endl;

		try
		{
			Steve.incrementGrade();
		}
		catch (const int e)
		{
			std::cerr << "X Error " << e << ": " << Steve << " not possible to increment grade" << std::endl;	
		}

		std::cout << std::endl;

		try
		{
			An.decrementGrade();
		}
		catch (const int e)
		{
			std::cerr << "X Error " << e << ": " << An << " not possible to increment grade" << std::endl;	
		}

		std::cout << std::endl;

		try
		{
			SteveCpy.decrementGrade();
			std::cout << ":: " << SteveCpy << "has being degraded." << Steve << " could not permit to have such a competitor" << std::endl;
		}
		catch (const int e)
		{
			std::cerr << "X Error " << e << ": " << SteveCpy << " not possible to increment grade" << std::endl;	
		}
		std::cout << std::endl;

	}
}
