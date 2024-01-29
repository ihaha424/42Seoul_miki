/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokhcho <seokhcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:34:57 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/14 20:35:27 by seokhcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

int	ft_atoi(char *str, int cnt)
{
	int	idx;
	int	sign;
	int	digit;

	idx = 0;
	sign = 1;
	digit = 0;
	while ((str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n'
			|| str[idx] == '\r' || str[idx] == '\v' || str[idx] == '\f')
		&& (idx < cnt))
		idx++;
	while ((str[idx] == '+' || str[idx] == '-') && (idx < cnt))
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while ((str[idx] >= '0' && str[idx] <= '9') && (idx < cnt))
	{
		digit = digit * 10 + (str[idx] - '0');
		idx++;
	}
	return (sign * digit);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}
