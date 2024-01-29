/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:27:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 14:55:24 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


/*
	Orthodox Canonical Form
*/

WrongAnimal::WrongAnimal(void) : _type("Aniaml")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
//	Get Attributes Function
*/

const std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

/*
	Action Function
*/

void WrongAnimal::makeSound(void) const
{
	std::cout << "Sound: WrongAnimal~ WrongAnimal~" << std::endl;
}