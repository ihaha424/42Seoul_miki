/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/05 01:52:02 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char* av[])
{
	Harl			harl;

	if (ac != 2)
	{
		std::cout << "Argument Fail." << std::endl;
		return (1);
	}
	std::cout << std::endl;
	harl.complain(std::string(av[1]));
	return (0);
}