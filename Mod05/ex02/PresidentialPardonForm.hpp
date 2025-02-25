#ifndef PRESIDENTIALRANDOMFORM_H
# define PRESIDENTIALRANDOMFORM_H

# include "Form.hpp"
# include <string>

class Bureaucrat;

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm(void);

        int execute(Bureaucrat const &executor) const;
};

#endif
