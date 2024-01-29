/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:13:50 by dongmiki          #+#    #+#             */
/*   Updated: 2023/07/22 17:19:55 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int error_case)
{
	if (error_case == 0)
		ft_putstr_fd("Error\nSystem error.\n", 2);
	if (error_case == 1)
		ft_putstr_fd("Error\nNot a ber file.\n", 2);
	if (error_case == 2)
		ft_putstr_fd("Error\nMap file open fail.\n", 2);
	if (error_case == 3)
		ft_putstr_fd("Error\nMap is invalue value.\n", 2);
	if (error_case == 4)
	{
		ft_putstr_fd("Line is must be a wall\n", 2);
		ft_putstr_fd("Error\nMap is invalue value.\n", 2);
	}
	if (error_case == 5)
		ft_putstr_fd("Error\nInvalid number of arguments.\n", 2);
	exit(EXIT_FAILURE);
}
