#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string name, const int grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string 	&getName(void) const;
		int					getExecGradeRequired(void) const;
		bool				IsSigned(void) const;
		bool				beSigned(const Bureaucrat &b);
		void				setGradeExecRequired(int grade);

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
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeExecRequired;
		std::string			_signedBy;

};

std::ostream &operator<<(std::ostream &out, const Form &other);
#endif
