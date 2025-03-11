#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void) : _name("Ineffable Form"), _gradeExecRequired(1)
{
	this->_isSigned = false;
	std::cout << ":: Inneffable form has been created" << std::endl;
}

Form::Form(const std::string name, const int grade) : _name(name), _gradeExecRequired(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_isSigned = false;
	std::cout << ":: " << this->_name << " has been created." << std::endl;	
}

Form::Form(const Form &other) : _name(other._name), _gradeExecRequired(other.getExecGradeRequired())
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

int	Form::getExecGradeRequired(void) const
{
	return (this->_gradeExecRequired);
}

bool Form::IsSigned(void) const
{
	return (this->_isSigned);
}

bool Form::beSigned(const Bureaucrat &b)
{
	if (this->_isSigned)
	{
		std::cout << "X " << b.getName() << " couldn't sign " << this->_name << " because was already signed by " << this->_signedBy << "." << std::endl;
		return (false);
	}
	if (b.getGrade() <= this->_gradeExecRequired)
	{
		this->_isSigned = true;
		this->_signedBy = b.getName();
		std::cout << ":: " << b.getName() << " signed form " << this->_name << "." << std::endl;
		return (true);
	}
	else
	{
		std::cout << ":: "  << b.getName() << "'s grade is too low to sign form " << this->_name << "." << std::endl;
		return (false);
	}
}

const char *Form::GradeTooHighException::what() const throw()
{	
	return ("Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{	
	return ("Grade Too Low!");
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
	std::cout << "\n	:: Form name: " << other.getName() << std::endl; 
	std::cout << "	:: Form required grade: " << other.getExecGradeRequired() << std::endl; 
	if (other.IsSigned())
		out << "	:: Form status: " << "signed" << std::endl; 
	else
		out << "	:: Form status: " << "NOT signed" << std::endl; 
	return(out);
}



