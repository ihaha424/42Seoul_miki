/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:47:26 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 16:54:21 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int*a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int*tab, int size)
{
	int	count;
	int	start;

	count = 0;
	while (++count < size)
	{
		start = -1;
		while (++start < count)
		{
			if (tab[start] > tab[count])
			{
				ft_swap(&tab[start], &tab[count]);
			}
		}
	}
}
