/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:08:59 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 14:08:59 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

void Contact::input(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	first_name = first;
	last_name = last;
	nick_name = nick;
	phone_number = phone;
	darkest_secret = secret;
}

void Contact::print_section(std::string section)
{
	int size;

	size = section.size();
	if (size > 10)
	{
		for(int tmp = 0; tmp < 9; tmp++)
			std::cout << section[tmp];
		std::cout << ".|";
	}
	else
	{
		std::cout << section;
		while(++size < 11)
			std::cout << " ";
		std::cout << "|";
	}
}

void Contact::visualition()
{
	print_section(first_name);
	print_section(last_name);
	print_section(nick_name);
}

void Contact::show_all()
{
	std::cout << "First Name:\n";
	std::cout << "\t" << first_name << std::endl;
	std::cout << "Last Name:\n";
	std::cout << "\t" << last_name << std::endl;
	std::cout << "Nick Name:\n";
	std::cout << "\t" << nick_name << std::endl;
	std::cout << "Phone Number:\n";
	std::cout << "\t" << phone_number << std::endl;
	std::cout << "Darkest Secret:\n";
	std::cout << "\t" << darkest_secret << "\n\n" << std::endl;
}