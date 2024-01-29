/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:51:09 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 15:06:51 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_rush(int x, int y, int x_count, int y_count)
{
	if (y_count == 0 && x_count == 0)
		ft_putchar('/');
	else if (y_count == 0 && x_count == x - 1)
		ft_putchar('\\');
	else if (y_count == y - 1 && x_count == 0)
		ft_putchar('\\');
	else if (y_count == y - 1 && x_count == x - 1)
		ft_putchar('/');
	else if (x_count == 0 || x_count == x - 1)
		ft_putchar('*');
	else if (y_count == 0 || y_count == y - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	x_count;
	int	y_count;

	y_count = -1;
	while (++y_count < y)
	{
		x_count = -1;
		while (++x_count < x)
		{	
			ft_print_rush(x, y, x_count, y_count);
		}
		ft_putchar('\n');
	}
}
