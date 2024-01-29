/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:37:11 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 14:09:01 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream> 

class Contact
{
	private:
		std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
		void print_section(std::string section);
	public:
		void input(std::string firtst, std::string last, std::string nick, std::string phone, std::string secret);
		void visualition();
		void show_all();
};

#endif