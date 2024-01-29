/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:16:01 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/07 12:11:18 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*		zombie;

	std::cout << std::endl;
	zombie = zombieHorde(10, "Horde");
	
	for (int i = 0; i < 10; i++)
		zombie[i].announce();

	delete[] zombie;
	return (0);
}
