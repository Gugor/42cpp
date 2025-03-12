#include <map>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form *Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void)
{
	std::cout << ":: A new itern has been created to be exploited... such a geat day for the lines of ink and paperwork." << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << ":: A cloned itern has been created to be exploited... such a geat day for the lines of ink and paperwork." << std::endl;

	if (this != &other)
		*this = other;
	std::cout << ":: A cloned itern has been created to be exploited... such a geat day for the lines of ink and paperwork." << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	std::cout << ":: A clonned itern has been created to be exploted... such a geat day for the lines of ink and paperwork." << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "An intern has fall of extenuation, after filling form after form... and never woke up again... And live keeps going in the burocrats corridors." << std::endl;
};


const char *Intern::UnableToMakeFormException::what() const throw()
{
	return ("No such form");	
}

Form *Intern::makeForm(const std::string &formname, std::string const &target)
{
	typedef Form* (Intern::*CreateFunc)(const std::string&);
	CreateFunc makeForms[3] = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm};
	std::string names[3] = {"ShrubberyCreationForm", "RomotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if (formname == names[i])
			return	(this->*makeForms[i])(target);
	}
	throw UnableToMakeFormException();
}
