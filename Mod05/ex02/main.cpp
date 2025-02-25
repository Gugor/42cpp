
#include <random>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{	
	{
		Bureaucrat An;
		Bureaucrat En("En", 25, 5);
		Bureaucrat Steve("Steve", 1, 1);
		Bureaucrat SteveCpy;
		ShrubberyCreationForm	shcf1("shcf1");
		RobotomyRequestForm		rbtm("Steve");
		PresidentialPardonForm	ppf("Robbie");
		SteveCpy = Steve;

		std::cout << std::endl;
		std::srand(std::time(0));
		try 
		{
			Steve.executeForm(shcf1);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		try 
		{
			Steve.executeForm(rbtm);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		try 
		{
			An.executeForm(ppf);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		try 
		{
			En.executeForm(ppf);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}




		std::cout << std::endl;
	}
}
