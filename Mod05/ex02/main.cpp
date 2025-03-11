
#include <cstdlib>
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
		Bureaucrat Un("Un", 24, 3);
		Bureaucrat Steve("Steve", 1, 1);
		Bureaucrat Diskard("Diskard", 26, 5);
		Bureaucrat SteveCpy;
		ShrubberyCreationForm	shcf1("shcf1");
		RobotomyRequestForm		rbtm("Robert");
		PresidentialPardonForm	ppf("Robbie");
		PresidentialPardonForm	ppf2("Grantt");
		SteveCpy = Steve;

		std::cout << std::endl;
		std::srand(std::time(0));
		try 
		{
			Steve.executeForm(shcf1);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
		try 
		{
			Steve.executeForm(rbtm);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
		try 
		{
			An.executeForm(ppf);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
		try 
		{
			En.executeForm(ppf);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
		try 
		{
			Un.executeForm(ppf);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
		try 
		{
			Diskard.executeForm(ppf2);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		std::cout << std::endl;
	}
}
