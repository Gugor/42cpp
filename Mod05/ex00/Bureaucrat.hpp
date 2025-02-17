
#ifndef BUREAUCRATE_H
# define BUREAUCRATE_H

# include <iostream>
# include <string>

class Bureaucrat 
{
	private:
		const std::string	_name;
		int			_grade;
		static const int	GradeTooHighException = 500;
		static const int	GradeTooLowException = 505;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string &getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);


#endif
