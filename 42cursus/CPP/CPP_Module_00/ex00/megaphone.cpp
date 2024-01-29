/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:58:27 by dongmiki          #+#    #+#             */
/*   Updated: 2023/11/21 16:40:41 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1 ; i < ac ; i++)
	{
		for (int j = 0 ; j < (int)strlen(av[i]) ; j++)
		{
			std::cout << (char)toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}