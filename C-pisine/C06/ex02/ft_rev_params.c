/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:44:27 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/11 10:44:50 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	temp;
	int	i;

	temp = argc - 1;
	while (temp >= 1)
	{	
		i = 0;
		while (argv[temp][i])
		{
			write(1, &argv[temp][i], 1);
			i++;
		}
		write(1, "\n", 1);
		temp--;
	}
	return (0);
}
