/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/12 12:54:07 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
	Orthodox Canonical Form
*/

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
	Action Function
*/

void Dog::makeSound(void) const
{
	std::cout << "Sound: Dog~ Dog~" << std::endl;
}