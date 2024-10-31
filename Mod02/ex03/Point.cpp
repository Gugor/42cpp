#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other)
{
	if (*this != other)
	{
		this->_x = other.x;
		this->_y = other.y;
	}
}

Point::~Point() {}

Fixed Point::getX()
{
	return (this->_x);
}

Fixed Point::getrY()
{
	return (this->_y);
}




