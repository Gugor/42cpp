#include <fstream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Ineffable RobotomyRequestForm", 72, 45)
{
	std::cout << ":: Ineffable RobotomyRequestForm has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form(target, 72, 45)
{
	std::cout << ":: " << getName() << " has been created." << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other)
{
	std::cout << ":: RobotomyRequestForm " << getName() << " has been carefully copied." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        Form::operator=(other);
        std::cout << ":: RobotomyRequestForm " << getName() << " has been carefully assigned." << std::endl;
    }
    return (*this);
}


int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	int rand;
    Form::execute(executor);
    
	std::cout << ":: brrrrrrriiiizzz..." << std::endl; 
	rand = std::rand() % 2;
	std::cout << "	:: Roll: " << rand << std::endl;
	if (rand >= 1)
		std::cout << "	:: √ " << this->getName() << " has been successfully robotomized." << std::endl; 
	else
		std::cout << "	:: X " << this->getName() << "'s  robotomization has failed." << std::endl; 
    return 0;
}

