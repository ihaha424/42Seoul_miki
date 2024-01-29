/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:51:45 by dongmiki          #+#    #+#             */
/*   Updated: 2023/07/06 13:51:51 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	int	temp;

	temp = 0;
	if (str == NULL)
		return (temp);
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}
