/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:42:30 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/11 10:42:53 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	temp;

	temp = 0;
	(void)argc;
	while (argv[0][temp])
	{
		write(1, &argv[0][temp], 1);
		temp++;
	}
	ft_putchar('\n');
	return (0);
}
