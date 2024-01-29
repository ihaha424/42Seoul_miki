/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:46:43 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/11 15:52:08 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		/*
		//	Orthodox Canonical Form
		*/
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		
		~ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& rhs);
		
		/*
			Action Function
		*/
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif