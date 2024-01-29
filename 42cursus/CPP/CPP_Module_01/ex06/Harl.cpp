/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:09:23 by dongmiki          #+#    #+#             */
/*   Updated: 2024/01/05 01:50:46 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) { }

Harl::~Harl(void) { }

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	int			i;
	void		(Harl::*levelFunction[4])(void);
	std::string	state[4];

	levelFunction[0] = &Harl::debug;
	levelFunction[1] = &Harl::info;
	levelFunction[2] = &Harl::warning;
	levelFunction[3] = &Harl::error;
	state[0] = "DEBUG";
	state[1] = "INFO";
	state[2] = "WARNING";
	state[3] = "ERROR";
	i = -1;
	while (++i < 4)
	{
		if (level.compare(state[i]) == 0)
			break ;
	}
	switch (i)
	{
		case 0:
			(this->*levelFunction[0])();
		case 1:
			(this->*levelFunction[1])();
		case 2:
			(this->*levelFunction[2])();
		case 3:
			(this->*levelFunction[3])();
	}
	if (i == 4)
		std::cout << "\nThe Level is Wrong Format." << std::endl;
}