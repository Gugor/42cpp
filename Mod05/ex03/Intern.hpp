
#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Intern 
{
	public:
		Intern(void);
		Intern &operator=(const Intern &other);
		~Intern(void);

		Form	*makeForm (const std::string &formname, std::string const &target);

};

#endif
