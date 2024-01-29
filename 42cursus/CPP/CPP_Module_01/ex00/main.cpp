/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:16:01 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/03 14:46:07 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie*		zombie;

	std::cout << std::endl;
	randomChump("Stack");
	
	std::cout << std::endl;
	zombie = newZombie("Heap");
	zombie->announce();

	delete zombie;
		
	return 0;
}