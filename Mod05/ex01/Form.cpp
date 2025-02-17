#include "Form.hpp"

Form::Form(void) : _name("Ineffable Form")
{
	this->_isSigned = 0;
	this->_permissionLevel = 1;
}

Form::Form(const std::string name, const int permLevel) : _name(name), _permissionLevel(permLevel)
{
	this->_isSigned = 0;
}

Form::Form(const Form &other) : _name(other->name), _permissionLevel(other->permissionLevel)
{
	if (this != &other)
	{
		this->_isSigned = &other->isSigned;
	}
}


