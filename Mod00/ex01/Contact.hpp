/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:46:08 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/20 00:24:07 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cctype>

namespace AwesomePhonebook
{
    class Contact 
    {
        public:
        
            //Constructors & Destructors
            Contact(void);
            ~Contact(void);
            
            //Init
            void createNew(void);

            //Getters
            std::string getName(void) const;
            std::string getSurname(void) const;
            std::string getNickname(void) const;
            std::string getCountryPrefix(void) const;
            std::string getPhone(void) const;
            std::string getEmail(void) const;
            std::string getFavoriteQuote(void) const;
            
        private:

            //Main attributes
            std::string _name;
            std::string _surname;
            std::string _nickname;
            std::string _countryPrefix;
            std::string _phone;
            std::string _email;
            std::string _favoritequote;

            //Private Methods
            std::string _getinput(std::string lable);
            std::string _getCountryPrefix(std::string lable);
            std::string _getPhone(std::string lable);
            int         _isValidPhone(std::string prefix);
            int         _isValidPrefix(std::string prefix);
            

        
    };
};
#endif