
#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point operator=(const Point &other);
		~Point();

		Fixed getX(); 
		Fixed getY(); 
}

#endif
