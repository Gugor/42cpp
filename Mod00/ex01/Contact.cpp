/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:43:30 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/24 20:09:10 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;   
}
		
Contact::~Contact()
{
	return ;   
}

std::string Contact::_getinput(std::string lable)
{
	std::string line;

	while (1)
	{
		std::cout << "\r" << lable;
		getline(std::cin, line);
		if (!std::cin)
			exit(2);
		if (line.empty())
			std::cout << "Ups, no content received. Please, insert some content";
		else	
			return (line);
	}
	return (NULL);
}

int Contact::_isValidPhone(std::string phone)
{
	int indx;
		
	if (phone.empty())
		return (0);
	indx = -1;
	while (phone[++indx])
		if (!isdigit(phone[indx]))
			return (0);
	return (1);
}

int	Contact::_isValidPrefix(std::string prefix)
{
	int indx;
		
	if (prefix.empty())
		return (0);
	if (prefix[0] != '+')
		return (0);
	indx = 0;
	while (prefix[++indx])
		if (!isdigit(prefix[indx]))
			return (0);
	return (1);
}
	
std::string Contact::_getCountryPrefix(std::string lable)
{
	std::string line;

	while (1)
	{
		std::cout << "\r" << lable;
		getline(std::cin, line);
		if (!std::cin)
			exit(2);
		if (line.empty())
			std::cout << "Ups, no content received. Please, insert some content";
		else	
		{
			if (!Contact::_isValidPrefix(line))
			{
				std::cout << "This is not avalid country prefix. Correct format: +34 " << std::endl;
				continue;
			}
			return (line);
		}
	}
	return (NULL);
}

std::string Contact::_getPhone(std::string lable)
{
	std::string line;

	while (1)
	{
		std::cout << "\r" << lable;
		getline(std::cin, line);
		if (!std::cin)
			exit(2);
		if (line.empty())
			std::cout << "Ups, no content received. Please, insert some content";
		else	
		{
			if (!Contact::_isValidPhone(line))
			{
				std::cout << "This is not avalid phone number. Correct format: 600000000 " << std::endl;
				continue;
			}
			return (line);
		}
	}
	return (NULL);
}

void Contact::createNew()	
{
	this->_name				= Contact::_getinput(std::string("Name: "));	
	this->_surname 			= Contact::_getinput(std::string("Last Name: "));	
	this->_nickname 		= Contact::_getinput(std::string("Nickname: "));	
	this->_countryPrefix 	= Contact::_getCountryPrefix(std::string("Contry Prefix: "));	
	this->_phone 			= Contact::_getPhone(std::string("Phone: "));	
	this->_favoritequote 	= Contact::_getinput(std::string("Favorite Quote: "));	
}

std::string Contact::getName(void) const
{
	return (this->_name);
}

std::string Contact::getSurname(void) const
{
	return (this->_surname);
}
	
std::string Contact::getNickname(void) const
{
	return (this->_nickname);
}
	
std::string Contact::getCountryPrefix(void) const
{
	return (this->_countryPrefix);
}

std::string Contact::getPhone(void) const
{
	return (this->_phone);
}
	
std::string Contact::getEmail(void) const
{
	return (this->_email);
}
	
std::string Contact::getFavoriteQuote(void) const
{
	return (this->_favoritequote);
}

