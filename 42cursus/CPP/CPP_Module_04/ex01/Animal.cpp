/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/12 12:48:49 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
	Orthodox Canonical Form
*/

Animal::Animal(void) : _type("Aniaml")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
//	Get Attributes Function
*/

const std::string	Animal::getType(void) const
{
	return (this->_type);
}

/*
	Action Function
*/

void Animal::makeSound(void) const
{
	std::cout << "Sound: Animal~ Animal~" << std::endl;
}