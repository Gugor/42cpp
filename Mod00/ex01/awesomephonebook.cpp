/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesomephonebook.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:04:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/20 18:53:00 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

using namespace AwesomePhonebook;

int main (int ac, char **av)
{
    Phonebook phbook;
    std::string line;

    (void)ac;
    (void)av;

    std::cout << BLD_BLUE << "-------------------------------------------------------------------------------" << RESET  << std::endl;
    std::cout << BLD_BLUE << "| " << BLD_YELLOW << "Welcome to Awesome Phone Book. Now you can ADD, SEARCH for contacts or EXIT" << BLD_BLUE << " |" << RESET  << std::endl;
    std::cout << BLD_BLUE << "-------------------------------------------------------------------------------" << RESET  << std::endl;
    while(1)
    {
        std::cout << BLD_WHITE << "\r> book: " << RESET;
        getline(std::cin, line);
        if (!std::cin)
            exit(1);
        if (line.empty())
            continue;
        if (line == "ADD")
            phbook.addContact();
        if (line == "SEARCH")
            phbook.searchContact();
        if (line == "EXIT")
            exit(0);
    }
    
    return (0);    
}