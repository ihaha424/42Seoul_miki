/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:18:46 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 20:01:21 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
}

HumanB::HumanB(std::string name, Weapon& weapon): _weapon(&weapon)
{
	this->_name = name;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " is delete" << std::endl;
}

void HumanB::attack(void)
{
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their fist" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << " equip " << this->_weapon->getType() << std::endl;
}
