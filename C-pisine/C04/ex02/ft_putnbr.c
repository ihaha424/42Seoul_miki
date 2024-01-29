/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:27:38 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/08 18:27:43 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	num;

	if (nb < 0)
	{
		num = -nb;
		ft_putchar('-');
	}
	else
	{
		num = nb;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar(num % 10 + 48);
}
