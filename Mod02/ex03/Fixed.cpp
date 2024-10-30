#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0) {}

Fixed::Fixed(const int num) : _integer(num << _fractions ) {}

Fixed::Fixed(const float num) : _integer(num * (1 << _fractions)) {}

Fixed::Fixed(const Fixed &other) : _integer(other._integer) {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_integer = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

bool Fixed::operator>(const Fixed &other) const
{
	return ((this->_integer > other.getRawBits()));
}

bool Fixed::operator<(const Fixed &other) const
{
	return ((this->_integer < other.getRawBits()));
}

bool Fixed::operator>=(const Fixed &other) const
{
	return ((this->_integer >= other.getRawBits()));
}

bool Fixed::operator<=(const Fixed &other) const
{
	return ((this->_integer <= other.getRawBits()));
}

bool Fixed::operator==(const Fixed &other) const
{
	return ((this->_integer == other.getRawBits()));
}

bool Fixed::operator!=(const Fixed &other) const
{
	return ((this->_integer != other.getRawBits()));
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed solution(this->toFloat() + other.toFloat());
	return (solution);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed solution(this->toFloat() - other.toFloat());
	return (solution);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed solution(this->toFloat() * other.toFloat());
	return (solution);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed solution(this->toFloat() / other.toFloat());
	return (solution);
}

Fixed Fixed::operator++()
{
	_integer++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++_integer;
	return (tmp);
}

Fixed Fixed::operator--()
{
	_integer--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--_integer;
	return (tmp);
}


Fixed &Fixed::min(Fixed &num1, Fixed  &num2)
{
	return ((num1 < num2) ? num1 : num2);	
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	return ((num1 < num2) ? num1 : num2);	
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	return((num1 > num2) ? num1 : num2);	
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	return ((num1 > num2) ? num1 : num2);	
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
	return (this->_integer);
}

void Fixed::setRawBits(const int raw)
{
	this->_integer = raw;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &val)
{
	out << val.toFloat();
	return (out);
}
