/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:19:02 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 19:38:35 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << this->_type << " is delete." << std::endl;
}

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	std::cout << this->_type << " is changed " << type << std::endl;
	this->_type = type;
}