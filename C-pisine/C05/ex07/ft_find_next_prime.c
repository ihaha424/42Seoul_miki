/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:17 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/11 17:17:55 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
{
	int	temp;

	temp = 2;
	if (nb < 2)
		return (0);
	while (temp < nb / temp)
	{
		if (nb % temp == 0)
			return (0);
		temp++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime1(nb) == 0)
		nb++;
	return (nb);
}
