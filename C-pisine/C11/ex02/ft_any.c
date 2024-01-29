/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:30:15 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 11:09:23 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (tab[i])
	{
		a = (*f)(tab[i]);
		if (a != 0)
			return (1);
		i++;
	}
	return (0);
}