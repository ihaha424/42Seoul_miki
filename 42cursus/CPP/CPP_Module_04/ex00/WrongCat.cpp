/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:27:06 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 14:56:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
	Orthodox Canonical Form
*/

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
	Action Function
*/

void WrongCat::makeSound(void) const
{
	std::cout << "Sound: WrongCat~ WrongCat~" << std::endl;
}