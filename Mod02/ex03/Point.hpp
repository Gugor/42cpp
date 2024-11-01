
#ifndef POINT_H
#define POINT_H

# include "Fixed.hpp"
# include <iostream>


class Point
{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		Fixed getX(void) const; 
		Fixed getY(void) const; 
		void show(std::string name);
};

#endif
