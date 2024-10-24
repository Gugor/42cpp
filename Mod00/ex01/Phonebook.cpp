/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:43:26 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/24 17:16:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_amount = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

std::string Phonebook::_fitToColumn(std::string data)
{
	std::string newData;

	newData = data;
	if (newData.length() > 9)
	{
		newData = newData.substr(0,8);
		newData = newData.replace(8, 1, std::string("."));
	}
	return (newData);
}

void Phonebook::addContact(void)
{
	this->_contacts[this->_amount % MAX_CONTACTS].createNew();
	this->printContactByIndex(this->_amount % MAX_CONTACTS);
	this->_amount++;
}

void Phonebook::listContacts(void)
{
	int indx;
	int max;
	
	indx = -1;
	std::cout << std::endl;
	std::cout << BLD_YELLOW <<"    Index|" << " Fst Name|" << " Lst Name|" << " Nick Name" << RESET << std::endl;
	if (this->_amount > MAX_CONTACTS)
		max = MAX_CONTACTS;
	else
		max = this->_amount;
	while(++indx < max)
		this->printSimpleContactByIndex(indx);
	std::cout << std::endl;
}

void Phonebook::printContactByIndex(int indx)
{
	Contact *contact;
	
	contact = &this->_contacts[indx];
	std::cout << "_________________________________________" << std::endl;
	std::cout << std::endl;
	std::cout << BLD_BLACK << ":: Name:\t\t" << BLD_WHITE << contact->getName() << RESET << std::endl;
	std::cout << BLD_BLACK << ":: Last Name:\t\t" << BLD_WHITE << contact->getSurname() << RESET << std::endl;
	std::cout << BLD_BLACK << ":: Nickname:\t\t" << BLD_WHITE << contact->getNickname() << RESET << std::endl;
	std::cout << BLD_BLACK << ":: Phone:\t\t" << BLD_WHITE << contact->getCountryPrefix() << " " << contact->getPhone() << RESET << std::endl;
	std::cout << BLD_BLACK << ":: Quote:\t\t" << BLD_WHITE << contact->getFavoriteQuote() << RESET << std::endl;
	std::cout << "_________________________________________" << std::endl;
	std::cout << std::endl;
}

void Phonebook::printSimpleContactByIndex(int indx)
{ 

	std::cout << std::setw(9) << 1 + indx << "|";
	std::cout << std::setw(9) << this->_fitToColumn(this->_contacts[indx].getName()) << "|";
	std::cout << std::setw(9) << this->_fitToColumn(this->_contacts[indx].getSurname()) << "|";
	std::cout << std::setw(10) << this->_fitToColumn(this->_contacts[indx].getNickname());
	std::cout << std::endl;
}

void Phonebook::searchContact(void)
{
	std::string	line;
	int			indx;
	
	if (this->_amount == 0)
	{
		std::cout << BLD_RED << "There are no contacts in this notebook. Please, add some to search." << RESET << std::endl;
		return ;
	}
	this->listContacts();
	while(1)
	{
		std::cout << BLD_WHITE << "\rSet contact index: " << RESET;
		getline(std::cin, line);
		indx = line[0] - 48;
		if (isdigit(line[0]) && indx <= this->_amount)
		{
			this->printContactByIndex(indx - 1);
			return ;
		}
		else
		{
			std::cout << std::endl;
			std::cout << BLD_RED <<"Worng index. Please choose one form the table below." << RESET << std::endl;
			std::cout << std::endl;
			this->listContacts();
			std::cout << std::endl;
			continue;
		}
	}
}

void Phonebook::exitPhonebook(void)
{
	exit(0);
}