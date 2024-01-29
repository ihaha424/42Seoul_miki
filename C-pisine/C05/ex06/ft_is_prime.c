/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:13 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/09 02:25:36 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	temp;

	temp = 2;
	if (nb < 2)
		return (0);
	while (temp < nb)
	{
		if (nb % temp == 0)
			return (0);
		temp++;
	}
	return (1);
}
