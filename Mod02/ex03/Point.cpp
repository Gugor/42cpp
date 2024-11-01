#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->_x = other.getX();
		this->_y = other.getY();
	}	
	return (*this);
}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

void Point::show(std::string name)
{
	std::cout << name << "[X:" << this->getX() << ",Y:" << this->getY() << "]" << std::endl;
}




