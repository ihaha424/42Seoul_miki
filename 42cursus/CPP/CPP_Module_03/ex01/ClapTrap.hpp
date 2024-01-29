/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:30:52 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 18:33:17 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		ClapTrap*		_target;
		bool			_printFlag;
		
	public:
		/*
		//	Orthodox Canonical Form
		*/
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		
		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& rhs);
		
		/*
		//	Get Attributes Function
		*/
		const std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		ClapTrap*		getTarget();

		/*
		//	Set Attributes Function
		*/
		void	setName(std::string name);
		void	setHitPoints(unsigned int hitPoints);
		void	setEnergyPoints(unsigned int energyPoints);
		void	setAttackDamage(unsigned int attackDamage);
		void	setTarget(ClapTrap& target);

		/*
		//	Output message (OnOff) Function
				:This function adjusts the output message only for 
				functions that are not given to the task.
		*/
		void	changeFlag(void);

		/*
			Action Function
		*/
		void attack(void);
		void attack(const std::string& target);
		void attack(ClapTrap& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif