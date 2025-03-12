#include <fstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("Ineffable ShrubberyCreationForm", 145, 137)
{
	std::cout << ":: Ineffable ShrubberyCreationForm has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): Form(target, 145, 137)
{
	std::cout << ":: " << this->getName() << " has been created." << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other)
{
	std::cout << ":: ShrubberyCreationForm " << this->getName() << " has been carefully copied." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        Form::operator=(other);
        std::cout << ":: ShrubberyCreationForm " << getName() << " has been carefully assigned." << std::endl;
    }
    return (*this);
}


int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    Form::execute(executor);
    
    std::string filename = getName() + "_shrubbery";
    std::ofstream sciifile(filename.c_str());
    
    if (!sciifile.good())
        throw std::runtime_error(":: X Failed to open file");
        
    sciifile << "SCII tree" << std::endl;
    sciifile.close();
    return 0;
}

