
#ifndef BUREAUCRATE_H
# define BUREAUCRATE_H

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Bureaucrat 
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const	std::string &getName(void) const;
		int		getGrade(void) const;
		int		signForm(Form &form);
		void	incrementGrade(void);
		void	decrementGrade(void);

	   	class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw(); 
				virtual ~GradeTooHighException() throw() {}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw(); 
				virtual ~GradeTooLowException() throw() {}
		};
	private:
		const std::string		_name;
		int				_grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif
