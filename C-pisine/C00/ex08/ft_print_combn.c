/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:37:03 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 15:16:14 by dongmiki         ###   ########.fr       */
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
		ft_putchar('-');
		num = -nb;
	}
	else
	{
		num = nb;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	ft_putchar((num % 10) + 48);
}

void	ft_print_num(int *num, int n)
{
	int	count;
	int	check;

	count = -1;
	while (++count < 10)
	{
		if (num[count] == 1)
		{
			ft_putnbr(count);
		}
	}
	check = 0;
	count = n + 1;
	while (0 < count--)
	{
		if (num[10 - count] == 1)
		{
			check++;
		}
	}
	if (check != n)
	{	
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_n_line(int n, int count, int *num, int start_num)
{
	if (n > 0)
	{	
		while (++count < 10)
		{
			num[count] = 1;
			ft_n_line (n - 1, count, num, start_num);
			num[count] = 0;
		}
	}
	else
	{	
		ft_print_num(num, start_num);
	}
}

void	ft_print_combn(int n)
{
	int	num[10];
	int	i;

	i = -1;
	while (++i < 10)
	{
		num[i] = 0;
	}
	ft_n_line (n, -1, num, n);
}
