#include <fstream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Ineffable PresidentialPardonForm", 25, 5)
{
	std::cout << ":: Ineffable PresidentialPardonForm has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form(target, 25, 5)
{
	std::cout << ":: " << getName() << " has been created." << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other)
{
	std::cout << ":: PresidentialPardonForm " << getName() << " has been carefully copied." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        Form::operator=(other);
        std::cout << ":: PresidentialPardonForm " << getName() << " has been carefully assigned." << std::endl;
    }
    return (*this);
}


int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
	std::cout << ":: " << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
    return 0;
}

