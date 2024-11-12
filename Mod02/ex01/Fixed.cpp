#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _integer(num << _fractions)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _integer(roundf(num * (1 << _fractions)))
{
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &c)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_integer = c._integer;
}

Fixed &Fixed::operator=(const Fixed &c)
{
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &c)
		this->_integer = c.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->_integer >> this->_fractions);
}

float Fixed::toFloat(void) const
{
	return (this->_integer / (float)(1 << this->_fractions));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_integer);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_integer = raw;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &val)
{
	out << val.toFloat();
	return (out);
}
