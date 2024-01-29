/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:27:48 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/10 11:26:11 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sign_check(int sign_count)
{
	if (sign_count % 2 == 1)
		return (-1);
	return (1);
}

int	ft_atoi(char *str)
{
	int	sign_count;
	int	value;

	sign_count = 0;
	value = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10;
		value = value + *str - 48;
		str++;
	}
	return (sign_check(sign_count) * value);
}
