
#include <random>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{	
	{
		Bureaucrat Jhon("Jhon", 1 , 1);
		Bureaucrat Low;
		Intern noone;
		Form	*smhs;

		std::cout << std::endl;
		std::srand(std::time(0));
		smhs = nullptr;
		try 
		{
			smhs =  noone.makeForm("ShrubberyCreationForm", "Summer House");
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		try
		{
			Jhon.executeForm(*smhs);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}

		std::cout << std::endl;
	}
	{
		Bureaucrat David("David", 25 , 5);
		Bureaucrat Low;
		Intern noone;
		Form	*smhs;

		std::cout << std::endl;
		std::srand(std::time(0));
		smhs = nullptr;
		try 
		{
			smhs =  noone.makeForm("RobotomyRequestForm", "Jhon");
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to create Form with such a low grade." << std::endl;	
		}
		try
		{
			David.executeForm(*smhs);
		}
		catch (std::exception &e)
		{
			std::cerr << "X Error " << e.what() << ": not possible to execute Form with such a low grade." << std::endl;	
		}

		std::cout << std::endl;
	}
}
