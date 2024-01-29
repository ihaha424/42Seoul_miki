/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:08:51 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 14:09:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int index;
		int exist[8];
		Contact people[8];
		void exit();
		void add();
		void search();
	public:
		void get_next_line();
};

#endif