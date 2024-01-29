/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:49:51 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
	Orthodox Canonical Form
*/

/*
	Orthodox Canonical Form
*/

Dog::Dog(void) : Animal()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
	try{
		this->_brain = new Brain();
	} catch (const std::bad_alloc& err) {
		std::cerr << "bad_alloc exception: " << err.what() << std::endl;
		this->_brain = NULL;
	}
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->_type = "Dog";
	try {
		this->_brain = new Brain();
	} catch (const std::bad_alloc& err) {
		std::cerr << "bad_alloc exception: " << err.what() << std::endl;
		this->_brain = NULL;
		return ;
	}
	*this->_brain = *src._brain;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		*this->_brain = *rhs._brain;
	}	
	return *this;
}

/*
//	Get Attributes Function
*/

std::string	Dog::getBrainIdeas(int i) const
{
	return this->_brain->getIdeas(i);
}

/*
//	Set Attributes Function
*/

void	Dog::setBrainIdeas(std::string ideas, int i)
{
	this->_brain->setIdeas(ideas, i);
}

/*
	Action Function
*/

void Dog::makeSound(void) const
{
	std::cout << "Sound: Dog~ Dog~" << std::endl;
}