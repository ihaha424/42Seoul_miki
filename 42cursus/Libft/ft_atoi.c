/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:09:57 by dongmiki          #+#    #+#             */
/*   Updated: 2022/12/29 19:31:36 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign_count;
	long	value;

	sign_count = 1;
	value = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_count = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10;
		value = value + *str - 48;
		if (value < 0)
			return (-1);
		str++;
	}
	return (sign_count * value);
}
