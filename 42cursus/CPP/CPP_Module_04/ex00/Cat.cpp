/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 17:55:21 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
	Orthodox Canonical Form
*/

Cat::Cat(void) : Animal()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

/*
	Action Function
*/

void Cat::makeSound(void) const
{
	std::cout << "Sound: Cat~ Cat~" << std::endl;
}