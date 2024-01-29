/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:45 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 18:32:52 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	Orthodox Canonical Form
*/

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
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

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " don't have HitPoints." << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", casusing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate(void)
{ 
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper Mode." << std::endl;
}