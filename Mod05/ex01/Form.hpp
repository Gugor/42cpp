#ifndef FORM_H
# define FORM_H

class Form
{
	public:
		Form(void);
		Form(const std::string name, const int permLevel);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);
		std::string &getName(void) const;
		bool	IsSigned(void) const;
		void	beSigned(const Bureaucrat &b) const;
		void	setPermissionLevel(int grade);

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
		const int		_permissionLevel;

};

#endif
