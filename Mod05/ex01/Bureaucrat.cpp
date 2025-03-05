
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Anonimous Bureaucrat")
{
	this->_grade 	= 150;
	std::cout << ":: An " << this->_name << " has join to the humonguous lower lines of whom devote their lives to paperwork and ink" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if(grade < 1)
		throw GradeTooHighException();
	else
	{
		this->_grade 	= grade;
		std::cout << ":: " << this->_name << " has join to the humonguous lines of whom devote their lives to paperwork and ink, with grade:" << this->_grade << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	if (other.getName().empty())
		out << "Undefined bureaucrat grade " << other.getGrade();
	else
		out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
	if (this != &other)
	{
		this->_grade	= other.getGrade();
		std::cout << ":: " << *this << ", is a deep copy of some other Bureaucrat" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << ":: Some will rejoice when they'll know that " << *this << " has left the ranks of paperworkers. The bureaucrats in the other hand are delight by the occasion of having to fill more boring forms. All is about perspective" << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
	if (this->_name.empty())
		std::cout << ":: Undefined has step UP in the breaucracy leader" << std::endl;
	else
		std::cout << ":: " << this->_name << "has step UP in the breaucracy leader" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
	if (this->_name.empty())
		std::cout << ":: Undefined has step DOWN in the breaucracy leader" << std::endl;
	else
		std::cout << ":: " << this->_name << "has step DOWN in the breaucracy leader" << std::endl;
}

int Bureaucrat::signForm(Form &form)
{
    form.beSigned(*this);
    return 0;
}

void Bureaucrat::executeForm(Form const &form)
{
	if (!form.IsSigned())
		std::cout << "Form " << form << " is not signed, therefore cannot be executed." << std::endl;
	else if (form.getGrade() < this->_grade)
		std::cout << *this << " has not enough grade level to execute this form." << std::endl;
	else
	{
		form.execute(this);
		std::cout << this->_name << " executed form " << form << "." << std::endl;
	}
}
