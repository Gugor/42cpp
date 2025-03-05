
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
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": " << Steve << " not possible to increment grade" << std::endl;	
		}

		std::cout << std::endl;

		try
		{
			An.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": " << An << " not possible to increment grade" << std::endl;	
		}

		std::cout << std::endl;

		try
		{
			SteveCpy.decrementGrade();
			std::cout << ":: " << SteveCpy << " has being degraded. " << Steve << " could not permit to have such a competitor" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": " << SteveCpy << " not possible to increment grade" << std::endl;	
		}
		std::cout << std::endl;

	}
}
