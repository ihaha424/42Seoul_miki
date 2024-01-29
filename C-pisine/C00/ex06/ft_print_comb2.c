/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 00:06:12 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/26 01:55:33 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(char *c)
{	
	char	temp;

	temp = ' ';
	write(1, c, 2);
	write(1, &temp, 1);
	write(1, c + 2, 2);
}

void	ft_last(char *num)
{
	if (! (num[0] == '9' && num[1] == '8' && num[2] == '9' && num[3] == '9'))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	char	num[4];

	num[0] = '0' - 1;
	num[1] = '0' -1;
	while (++num[0] <= '9')
	{
		while (++num[1] <= '9')
		{
			num[2] = num[0] -1;
			while (++num[2] <= '9')
			{
				num[3] = num[1];
				if (! (num[0] == num[2]))
				{
					num[3] = '0' -1;
				}
				while (++num[3] <= '9')
				{
					ft_putnum(&num[0]);
					ft_last(&num[0]);
				}
			}		
		}
		num[1] = '0' -1;
	}
}
