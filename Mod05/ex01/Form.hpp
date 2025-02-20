#ifndef FORM_H
# define FORM_H

class Form
{
	public:
		Form(void);
		Form(const std::string name, const int grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		std::string &getName(void) const;
		int			getExecGradeRequired(void) const;

		bool	IsSigned(void) const;
		bool	beSigned(const Bureaucrat &b);
		void	setGadeExecRequired(int grade);

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
		const std:string _name;
		bool		_isSigned;
		const int		_gradeExecRequired;

};

std::ostream &operato<<(std::ostream &out, const Form &other);

#endif
