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
		Form(const std::string target, const int grade, const int exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string 	&getName(void) const;
		int					getExecGradeRequired(void) const;
		int					getSignGradeRequired(void) const;
		bool				IsSigned(void) const;
		bool				beSigned(const Bureaucrat &b);
		virtual int			execute(Bureaucrat const &executor) const = 0;

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

		class SignGradeLevelTooLowException : public std::exception
		{
			public:
					virtual const char *what() const throw();
					virtual ~SignGradeLevelTooLowException() throw() {}
		};

		class ExecGradeLevelTooLowException : public std::exception
		{
			public:
					virtual const char *what() const throw();
					virtual ~ExecGradeLevelTooLowException() throw() {}
		};




	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		std::string			_signedBy;

};

std::ostream &operator<<(std::ostream &out, const Form &other);
#endif
