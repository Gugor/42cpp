/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:19 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/17 19:50:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string strtoupper(std::string str)
{
    for(int i = 0; str[i] ; i++)
        str[i] = std::toupper(str[i]);
    return (str);
}

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
        std::cout << strtoupper(av[i]) << " ";
    std::cout << std::endl;
    return (0);
}