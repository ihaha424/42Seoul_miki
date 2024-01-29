/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:04:18 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/05 01:50:00 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl			harl;
	std::string		state;

	while (state.compare("EXIT"))
	{
		std::cout << "Please input the Harl state(Level) information:\n(If you want to end, Please enter \"EXIT\")" << std::endl;
		std::cout << "\tDEBUG\n\tINFO\n\tWARNING\n\tERROR\n" << std::endl;
		std::getline(std::cin, state);
		if(std::cin.eof() || state.compare("EXIT") == 0)
			break;
		std::cout << "========================================" << std::endl;
		harl.complain(state);
		std::cout << "========================================" << std::endl;
	}
	
	return (0);
}