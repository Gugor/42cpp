/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:46:04 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/24 17:14:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# define MAX_CONTACTS 8
# include "Contact.hpp"
# include <string>
# include <cctype>
# include <iomanip>
# include <limits>
# include "Colours.hpp"

class Phonebook
{
	private:
		Contact _contacts[MAX_CONTACTS];
		int     _amount;
		std::string _fitToColumn(std::string data);

	public:
		Phonebook(void);
		~Phonebook(void);
		
		void createMaxContacts(void);
		void addContact(void);
		void searchContact(void);
		void exitPhonebook(void);
		void listContacts(void);
		void printContactByIndex(int indx);
		void printSimpleContactByIndex(int indx);
}; 
#endif

