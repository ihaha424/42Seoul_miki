/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:31 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 18:59:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		/*
		//	Orthodox Canonical Form
		*/
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& rhs);
		
		/*
			Action Function
		*/
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif