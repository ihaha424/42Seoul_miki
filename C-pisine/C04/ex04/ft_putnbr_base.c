/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:27:53 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/10 11:47:30 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

int	length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_up(char *base)
{
	int	i;
	int	j;

	if (length(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 127 || base[i] <= 32)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_length;
	long long	temp;

	if (check_up(base))
		return ;
	temp = nbr;
	base_length = length(base);
	if (temp < 0)
	{
		temp *= -1;
		print('-');
	}
	if (temp < base_length)
		print(base[temp]);
	else
	{
		ft_putnbr_base(temp / base_length, base);
		print(base[temp % base_length]);
	}
}
