#ifndef SCALARCONVERTER_H 
# define SCALARCONVERTER_H 

# include <iostream>
# include <stdlib.h>
# include <string>

typedef enum TYPES 
{
	CHART,
	FLTT,
	DBLT,
	INTT,
	IMP
}	t_types;

class ScalarConverter
{
	public:
		static void convert(std::string &s);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter(void);
};

#endif

