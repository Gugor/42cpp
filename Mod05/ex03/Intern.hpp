
#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

typedef Form (*t_makeForm)(std::string &target);

class Intern 
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		Form	*makeForm (const std::string &formname, std::string const &target);
		Form	*makeShrubberyForm(const std::string &target);
		Form	*makeRobotomyForm(const std::string &target);
		Form	*makePresidentialForm(const std::string &target);

		class UnableToMakeFormException : public std::exception
                {
                        public:
                                        virtual const char *what() const throw();
					virtual ~UnableToMakeFormException() throw() {}
                };

};

#endif
