/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:40:41 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/07 12:59:21 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char*str)
{
	int		count;
	int		num;
	char	*arr;

	arr = "0123456789abcdef";
	count = -1;
	while (str[++count])
	{
		if (32 <= str[count] && str[count] <= 126)
			ft_putchar(str[count]);
		else
		{
			ft_putchar('\\');
			num = str[count];
			if (str[count] < 0)
				num = str[count] + 256;
			ft_putchar(arr[num / 16]);
			ft_putchar(arr[num % 16]);
		}
	}
}
