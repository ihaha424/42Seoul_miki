/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:36:41 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/15 13:03:23 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char*str)
{
	int	temp;

	temp = 0;
	while (str[temp])
	{
		ft_putchar1(str[temp]);
		temp++;
	}
}
