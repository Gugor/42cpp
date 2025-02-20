#include "Form.hpp"

Form::Form(void) : _name("Ineffable Form")
{
	this->_isSigned = false;
	this->_permissionLevel = 1;
}

Form::Form(const std::string name, const int grade) : _name(name), _gradeExecRequired(grade)
{
	this->_isSigned = false;
}

Form::Form(const Form &other) : _name(other->name), _permissionLevel(other->getExecGradeRequiered)
{
	if (this != &other)
	{
		this->_isSigned = &other->isSigned;
	}
}

Form  &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other->getSignStatus();
		this->_gradeExecRequired = other->getExecGradeRequired();
	}
	return (this);
}

std::string &Form::getName(void) const
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
		std::cout << "Form " << this->_name << " has been already signed by " << this->_signedBy;
		return (false);
	}
	if (b->getGrade() <= this->_gradeExecRequired)
	{
		this->_isSigned = true;
		this->_signedBy = b->getName();
		return (true)
	}
	else
		return (false);
}


