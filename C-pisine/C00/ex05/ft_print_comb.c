/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:44:17 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/26 00:01:34 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = '0' -1;
	while (++num[0] <= '7')
	{
		num[1] = num[0];
		while (++num[1] <= '8')
		{
			num[2] = num[1];
			while (++num[2] <= '9')
			{
				ft_putchar(num[0]);
				ft_putchar(num[1]);
				ft_putchar(num[2]);
				if (! (num[0] == '7' && num[1] == '8' && num[2] == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
