#ifndef FLOAT_H
#define FLOAT_H

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		const static int _fractions = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &c);
		Fixed  &operator=(const Fixed &c);
		~Fixed();
		
		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif
