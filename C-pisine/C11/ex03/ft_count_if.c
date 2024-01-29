/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:40:09 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 11:16:58 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	a;
	int	count;

	count = 0;
	a = 0;
	i = 0;
	while ((*tab)[i])
	{
		a = (*f)(tab[i]);
		if (a != 0)
			count++;
		i++;
	}
	return (count);
}
