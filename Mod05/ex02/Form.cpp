#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void) : _name("Ineffable Form"), _signGrade(1), _execGrade(1)
{
	this->_isSigned = false;
	std::cout << ":: Inneffable form has been created" << std::endl;
}

Form::Form(const std::string name, const int grade, const int exec) : _name(name), _signGrade(grade), _execGrade(exec)
{
	if (grade > 150 || exec > 150)
		throw GradeTooLowException();
	else if (grade < 1 || exec < 1)
		throw GradeTooHighException();
	else
		this->_isSigned = false;
	std::cout << ":: " << this->_name << " has been created." << std::endl;	
}

Form::Form(const Form &other) : _name(other.getName()), _signGrade(other.getSignGradeRequired()), _execGrade(other.getExecGradeRequired())
{
	if (this != &other)
	{
		this->_isSigned = other.IsSigned();
		std::cout << ":: Form " << this->_name << " has been carefully copied." << std::endl;
	}
}

Form::~Form(void){}

Form  &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.IsSigned();
		std::cout << ":: Form " << this->_name << " has been carefully assigned." << std::endl;
	}
	return (*this);
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGradeRequired(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGradeRequired(void) const
{
	return (this->_execGrade);
}

bool Form::IsSigned(void) const
{
	return (this->_isSigned);
}

bool Form::beSigned(const Bureaucrat &b)
{
	if (this->_isSigned)
	{
		std::cout << b.getName() << " couldn't sign " << this->_name << " because was already signed by " << this->_signedBy << "." << std::endl;
		return (false);
	}
	if (b.getSignGrade() <= this->_signGrade)
	{
		this->_isSigned = true;
		this->_signedBy = b.getName();
		std::cout << b.getName() << " signed form " << this->_name << "." << std::endl;
		return (true);
	}
	else
	{
		std::cout << ":: "  << b.getName() << "'s grade is too low to sign form " << this->_name << "." << std::endl;
		return (false);
	}
}

int Form::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " sending order to execute form..." << std::endl; 
	return (0);
}

const char *Form::GradeTooHighException::what() const throw()
{	
	return ("Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{	
	return ("Grade Too Low!");
}

const char *Form::ExecGradeLevelTooLowException::what() const throw()
{	
	return ("Execution level to low to execute this form.");
}

const char *Form::SignGradeLevelTooLowException::what() const throw()
{	
	return ("Sign level to low to execute this form.");
}


std::ostream &operator<<(std::ostream &out, const Form &other)
{
	std::cout << "\n	:: Form name: " << other.getName() << std::endl; 
	std::cout << "	:: Form required sign grade: " << other.getSignGradeRequired() << std::endl; 
	if (other.IsSigned())
		out << "	:: Form status: " << "signed"  << std::endl; 
	else
		out << "	:: Form status: " << "NOT signed" << std::endl; 
	std::cout << "	:: Form required execution grade: " << other.getSignGradeRequired() << std::endl; 
	return(out);
}



