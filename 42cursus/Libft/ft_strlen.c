/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:29:54 by dongmiki          #+#    #+#             */
/*   Updated: 2023/10/30 20:02:30 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
