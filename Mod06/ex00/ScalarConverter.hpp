#ifndef SCALARCONVERTER_H 
# define SCALARCONVERTER_H 

# include <iostream>
# include <string>

class ScalarConverter
{
public:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &scalarconverter);
	~ScalarConverter(void);
	std::string getName(void) const; 
private:
	std::string _name;
};

#endif

