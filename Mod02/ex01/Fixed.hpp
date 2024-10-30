#ifndef FLOAT_H
#define FLOAT_H

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _integer;
		const static int _fractions = 8;

	public:
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &c);
		Fixed  &operator=(const Fixed &c);
		~Fixed();
		
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(const int raw);
};
std::ostream	&operator<<(std::ostream &out, const Fixed &val);

#endif
