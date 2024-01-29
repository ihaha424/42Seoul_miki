/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:12:37 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/08 21:08:56 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	long long	i;
	long long	count;
	int			*add;

	i = (long long)max - (long long)min;
	if (!(i > 0))
		return (0);
	add = (int *)malloc(sizeof(int) * i);
	count = 0;
	while (count < i)
	{
		add[count] = min + count;
		count++;
	}
	return (add);
}
