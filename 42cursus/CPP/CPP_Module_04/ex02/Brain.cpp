/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:53:55 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/15 18:20:41 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


/*
	Orthodox Canonical Form
*/

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdeas(i);
	return *this;
}

/*
//	Get Attributes Function
*/

std::string	Brain::getIdeas(int i) const
{
	return this->_ideas[i];
}

/*
//	Set Attributes Function
*/

void	Brain::setIdeas(std::string ideas, int i)
{
	this->_ideas[i] = ideas;
}