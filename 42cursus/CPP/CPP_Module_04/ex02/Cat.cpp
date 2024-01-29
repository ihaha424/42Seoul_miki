/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:22:15 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:36:23 by dongmiki         ###   ########.fr       */
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
	try{
		this->_brain = new Brain();
	} catch (const std::bad_alloc& err) {
		std::cerr << "bad_alloc exception: " << err.what() << std::endl;
		this->_brain = NULL;
	}
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->_type = "Cat";
	try {
		this->_brain = new Brain();
	} catch (const std::bad_alloc& err) {
		std::cerr << "bad_alloc exception: " << err.what() << std::endl;
		this->_brain = NULL;
		return ;
	}
	*this->_brain = *src._brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
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

std::string	Cat::getBrainIdeas(int i) const
{
	return this->_brain->getIdeas(i);
}

/*
//	Set Attributes Function
*/

void	Cat::setBrainIdeas(std::string ideas, int i)
{
	this->_brain->setIdeas(ideas, i);
}


/*
	Action Function
*/

void Cat::makeSound(void) const
{
	std::cout << "Sound: Cat~ Cat~" << std::endl;
}