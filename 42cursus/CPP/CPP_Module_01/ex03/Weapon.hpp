/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:19:05 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/07 12:14:21 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string&	getType(void) const;
		void setType(std::string type);
};

#endif
