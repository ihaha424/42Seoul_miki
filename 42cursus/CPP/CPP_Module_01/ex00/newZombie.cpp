/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:15:56 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/03 14:40:40 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie*	zombie;

	try {
		zombie = new Zombie(name);
	} catch (const std::bad_alloc& e) {
		std::cerr << "bad_alloc exception: " << e.what() << std::endl;
		zombie = NULL;
	}
	return zombie;
}