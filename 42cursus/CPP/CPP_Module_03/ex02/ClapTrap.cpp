/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:30:50 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/12 14:25:39 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
	Orthodox Canonical Form
*/

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(0), _energyPoints(0), _attackDamage(0), _target(NULL), _printFlag(true)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _target(NULL), _printFlag(true)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	Get Attributes Function
*/

const std::string	ClapTrap::getName() const
{
	if (_printFlag)
		std::cout << "getName member function called" << std::endl;
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	if (_printFlag)
		std::cout << "getHitPoints member function called" << std::endl;
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	if (_printFlag)
		std::cout << "getEnergyPoints member function called" << std::endl;
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	if (_printFlag)
		std::cout << "getAttackDamage member function called" << std::endl;
	return (this->_attackDamage);
}

ClapTrap*	ClapTrap::getTarget()
{
	if (_printFlag)
		std::cout << "getTarget member function called" << std::endl;
	return (this->_target);
}

/*
	Set Attributes Function
*/

void	ClapTrap::setName(std::string name)
{
	if (_printFlag)
		std::cout << "setName member function called" << std::endl;
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
	if (_printFlag)
		std::cout << "setHitPoints member function called" << std::endl;
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	if (_printFlag)
		std::cout << "setEnergyPoints member function called" << std::endl;
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	if (_printFlag)
		std::cout << "setAttackDamage member function called" << std::endl;
	this->_attackDamage = attackDamage;
}

void	ClapTrap::setTarget(ClapTrap& target)
{
	if (_printFlag)
		std::cout << "setTatget member function called" << std::endl;
	this->_target = &target;
}

/*
//	Output message (OnOff) Function
*/

void	ClapTrap::changeFlag(void)
{
	if (this->_printFlag)
		this->_printFlag = false;
	else
		this->_printFlag = true;
}

/*
	Action Function
*/

void ClapTrap::attack(void)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have HitPoints." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else if (this->_target == NULL)
		std::cout << "ClapTrap " << this->_name << " don't have Target." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << this->_target->getName() << ", casusing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		this->_target->takeDamage(this->_hitPoints);
	}
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have HitPoints." << std::endl;
	if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", casusing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ClapTrap::attack(ClapTrap& target)
{
	setTarget(target);
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have HitPoints." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << this->_target->getName() << ", casusing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		this->_target->takeDamage(this->_attackDamage);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take damage " << amount << ", remain HitPoints is " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have HitPoints." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " don't have EnergyPoints." << std::endl;
	else
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " is repaired " << amount << " HitPoints" << ", Remain HitPoints is " << this->_hitPoints << std::endl;
	}
}