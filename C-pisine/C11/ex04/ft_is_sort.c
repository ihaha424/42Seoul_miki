/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:18:45 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 11:47:53 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	first;

	if (length <= 0)
		return (-1);
	if (length <= 2)
		return (1);
	first = (*f)(tab[0], tab[1]);
	i = 1;
	while (tab[++i])
	{
		if (first == 0)
			first = (*f)(tab[i - 1], tab[i]);
		else if (first > 0)
		{
			if ((*f)(tab[i - 1], tab[i]) < 0)
				return (0);
		}
		else
		{
			if ((*f)(tab[i - 1], tab[i]) > 0)
				return (0);
		}
	}
	return (1);
}
