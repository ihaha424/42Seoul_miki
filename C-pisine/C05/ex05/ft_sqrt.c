/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:09 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/08 18:29:11 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	num;
	unsigned int	nb1;

	num = 0;
	if (nb <= 0)
		return (0);
	nb1 = nb;
	while (num * num <= nb1)
	{
		if (num * num == nb1)
			return (num);
		num++;
	}
	return (0);
}
