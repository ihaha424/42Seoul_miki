/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:53:28 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/12 22:14:47 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_length(unsigned int a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static int	ft_un_itoa(unsigned int a)
{
	char	*temp;
	int		len;
	int		index;

	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = check_length(a);
	index = len;
	temp = malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		return (0);
	temp[index] = '\0';
	index--;
	while (index >= 0)
	{
		temp[index] = '0' + (a % 10);
		a /= 10;
		index--;
	}
	write(1, temp, len);
	free(temp);
	return (len);
}

int	printf_u(va_list ap)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(ap, size_t);
	len = ft_un_itoa(arg);
	return (len);
}
