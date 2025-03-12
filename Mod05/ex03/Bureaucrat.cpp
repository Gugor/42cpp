
# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Anonimous Bureaucrat")
{
	this->_signGrade 	= 150;
//	std::cout << ":: An " << this->_name << " has join to the humonguous lower lines of whom devote their lives to paperwork and ink" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade, const int exec) : _name(name)
{
	if (grade > 150 || exec > 150)
		throw GradeTooLowException();
	else if(grade < 1 || exec < 1)
		throw GradeTooHighException();
	else
	{
		this->_signGrade 	= grade;
		this->_execGrade 	= exec;
//		std::cout << ":: " << this->_name << " has join to the humonguous lines of whom devote their lives to paperwork and ink, with " << this->_signGrade << "/" << this->_execGrade << " for sign and execution levels." <<  std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
	if (other.getName().empty())
		out << "Undefined bureaucrat grade " << other.getSignGrade();
	else
		out << other.getName() << ", bureaucrat grade " << other.getSignGrade();
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

Bureaucrat::Bureaucrat(const Bureaucrat & other)
{
	if (this != &other)
	{
		this->_signGrade	= other.getSignGrade();
//		std::cout << ":: " << *this << ", is a deep copy of some other Bureaucrat" << std::endl;
	}
} 

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
	if (this != &other)
	{
		this->_signGrade	= other.getSignGrade();
//		std::cout << ":: " << *this << ", is a deep assigment copy of some other Bureaucrat" << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
//	std::cout << ":: Some will rejoice when they'll know that " << *this << " has left the ranks of paperworkers. The bureaucrats in the other hand are delight by the occasion of having to fill more boring forms. All is about perspective" << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Bureaucrat::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_signGrade <= 1)
		throw GradeTooHighException();
	this->_signGrade--;
	if (this->_name.empty())
		std::cout << ":: Undefined has step UP in the breaucracy leader" << std::endl;
	else
		std::cout << ":: " << this->_name << " has step UP in the breaucracy leader" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_signGrade >= 150)
		throw GradeTooLowException();
	this->_signGrade++;
	if (this->_name.empty())
		std::cout << ":: Undefined has step DOWN in the breaucracy leader" << std::endl;
	else
		std::cout << ":: " << this->_name << " has step DOWN in the breaucracy leader" << std::endl;
}

int Bureaucrat::signForm(Form &form) const
{
    form.beSigned(*this);
    return 0;
}

void Bureaucrat::executeForm(Form const &form)
{
	std::cout << *this << " executing form" << form << std::endl;
	form.execute((Bureaucrat const &)*this);
	std::cout << "  :: √ " << this->getName() << " executed " << form.getName() << std::endl;
}

