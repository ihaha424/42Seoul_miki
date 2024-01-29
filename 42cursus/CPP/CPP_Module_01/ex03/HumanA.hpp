/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:18:54 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/04 19:40:06 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void attack(void);
};

#endif