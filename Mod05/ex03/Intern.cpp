#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << ":: A new itern has being, created to be exploted... such a geat day for the lines of ink and paperwork." << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
		*this = other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "An intern has fall of extenuation, after filling form after form... and never woke up again... And live keeps going in the burocrats corridors." << std::endl;
};

Form *Intern::makeForm(const std::string &formname, std::string const &target)
{
	if (formname == "ShrubberyCreationForm")
	{
		std::cout << "Intern creates " << formname << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (formname == "RobotomyRequestForm")
	{
		std::cout << "Intern creates " << formname << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (formname == "PresidentialPardonForm")
	{
		std::cout << "Intern creates " << formname << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << formname << " doesn't correspond to any valid form." << std::endl;
		return (NULL);
	}
}
