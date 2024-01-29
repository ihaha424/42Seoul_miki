/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:40 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/07 13:06:28 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	hexa_add_print(void*str)
{
	int					temp;
	unsigned long long	addr;
	char				address[16];
	char				*hex;

	addr = (long)str;
	hex = "0123456789abcdef";
	temp = 16;
	while (--temp >= 0)
	{
		address[temp] = hex[addr % 16];
		addr = addr / 16;
	}
	while (++temp < 16)
	{
		write(1, &address[temp], 1);
	}
	write(1, ":", 1);
}

void	hexa_st_print(char *addr, int size2)
{
	int		count;
	char	*arr;
	int		tf;

	tf = 1;
	arr = "0123456789abcdef";
	count = -1;
	while (++count < 16)
	{	
		if (count < 16 && tf && count < size2)
		{
			if (count % 2 == 0)
				ft_putchar(' ');
			ft_putchar(arr[addr[count] / 16]);
			ft_putchar(arr[addr[count] % 16]);
		}
		else
		{	
			tf = 0;
			if (count % 2 == 0)
				ft_putchar(' ');
			write(1, "  ", 2);
		}
	}
}

void	st_print(char *addr, int size2)
{
	int	count;

	count = -1;
	while (++count < size2 && count < 16)
	{
		if (32 <= addr[count] && addr[count] <= 126)
			ft_putchar(addr[count]);
		else
			ft_putchar('.');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	count;
	int				num;
	int				size2;

	num = (int)addr;
	count = 0;
	while (count < size)
	{	
		if (count % 16 == 0)
		{	
			size2 = size - count;
			hexa_add_print(addr + count);
			hexa_st_print(addr + count, size2);
			ft_putchar(' ');
			st_print(addr + count, size2);
			write(1, "\n", 2);
		}
			count++;
	}
	return (addr);
}
