/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:47:32 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/07 14:41:58 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	zombie;

	try {
		zombie = new Zombie[N];
	} catch (const std::bad_alloc& e) {
		std::cerr << "bad_alloc exception: " << e.what() << std::endl;
		zombie = NULL;
		return zombie;
	}
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return zombie;
}
