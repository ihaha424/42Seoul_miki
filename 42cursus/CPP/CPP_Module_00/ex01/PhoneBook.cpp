/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:08:46 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/05 01:36:18 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

void PhoneBook::exit()
{
	::exit(0);
}

void PhoneBook::add()
{	
	std::string str[5];
	
	std::cout << "Please input the people information:\n";
	std::cout << "\tFirst Name:\n";
	std::getline(std::cin, str[0]);
	std::cout << "\tLast Name:\n";
	std::getline(std::cin, str[1]);
	std::cout << "\tNick Name:\n";
	std::getline(std::cin, str[2]);
	std::cout << "\tPhone Number:\n";
	std::getline(std::cin, str[3]);
	std::cout << "\tDarkest Secret:\n";
	std::getline(std::cin, str[4]);
	people[index].input(str[0], str[1], str[2], str[3], str[4]);
	exist[index] = 1;
	index = (index + 1) % 8;
}

void PhoneBook::search()
{
	int i;
	int size;
	int	num;
	std::string number;
	std::stringstream temp;

	i = -1;
	std::cout << "Index     |First Name|Last Name |Nick Name |" << std::endl;
	while(exist[++i])
	{
		std::cout << i + 1 << "         |";
		people[i].visualition();
		std::cout << std::endl;
	}
	std::cout << "\nEnter the number you want to see:\n(Cancel if you enter other values)" << std::endl;
	std::getline(std::cin, number);
	temp << number;
    temp >> num;
	if (--num >= 0 && num < 8 && exist[num])
		people[num].show_all();
	else
		std::cout << "\nThe number you are looking for is not data." << std::endl;
}

void PhoneBook::get_next_line()
{
	std::string gnl;

	std::cout << "Please input the action:\n\tEXIT\n\tADD\n\tSEARCH\n(Else the input is discarded.)" << std :: endl;
	std::getline(std::cin, gnl);
	if (!gnl.compare("EXIT"))
		PhoneBook::exit();
	else if(!gnl.compare("ADD"))
		PhoneBook::add();
	else if(!gnl.compare("SEARCH"))
		PhoneBook::search();
}

int main()
{
	std::cout << "Hello This is unbelievable technology Phone Book!\n\n";
	PhoneBook phone_book;
	while(1)
	{
		phone_book.get_next_line();
		if (std::cin.eof())
		  	break ;
	}
	return 0;
}
