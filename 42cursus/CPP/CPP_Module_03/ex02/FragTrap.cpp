/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:29 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 19:05:05 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
	Orthodox Canonical Form
*/

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
		this->_target = rhs._target;
	}
	return *this;
}

/*
	Action Function
*/

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " don't have HitPoints." << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "FragTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", casusing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is request a positive high fives." << std::endl;
}