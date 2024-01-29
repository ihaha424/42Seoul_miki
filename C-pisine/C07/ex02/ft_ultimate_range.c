/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:20:08 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 21:13:44 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	i;
	long long	count;

	i = (long long)max - (long long)min;
	if (i <= 0)
		return (0);
	*range = (int *)malloc(sizeof(int) * i);
	if (*range == NULL)
	{
		*range = NULL;
		return (-1);
	}
	count = 0;
	while (count < i)
	{
		range[0][count] = min + count;
		count++;
	}
	return (i);
}
