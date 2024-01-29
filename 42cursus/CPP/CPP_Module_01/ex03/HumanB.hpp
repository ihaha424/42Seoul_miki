/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:18:58 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/10 15:21:43 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon& weapon);
};

#endif