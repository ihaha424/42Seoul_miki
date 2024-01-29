/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:36:36 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/15 20:36:27 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	add(int a, int b);
int	sup(int a, int b);
int	div(int a, int b);
int	mul(int a, int b);
int	mod(int a, int b);

void	ft_putnbr(int nb)
{
	unsigned int	num;
	char			c;

	if (nb < 0)
	{
		num = -nb;
		write(1, "-", 1);
	}
	else
	{
		num = nb;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
	}
	c = num % 10 + 48;
	write(1, &c, 1);
}

void	process(int (*f)(int, int ), int x, int y)
{
	ft_putnbr(((*f)(x, y)));
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	sign_count;
	int	value;

	sign_count = 1;
	value = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_count *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10;
		value = value + *str - 48;
		str++;
	}
	return (sign_count * value);
}

void	print(char *argv[], int a, int b)
{
	if (argv[2][0] == '+')
		process(add, a, b);
	else if (argv[2][0] == '-')
		process(sup, a, b);
	else if (argv[2][0] == '*')
		process(mul, a, b);
	else if (argv[2][0] == '/')
	{
		if (b == 0)
			write(1, "Stop : division by zero\n", 24);
		else
			process(div, a, b);
	}
	else if (argv[2][0] == '%')
	{
		if (b == 0)
			write(1, "Stop : modulo by zero\n", 22);
		else
			process(mod, a, b);
	}
	else
		write(1, "0\n", 2);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc != 4)
		return (0);
	if (argv[2][1] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	print(argv, a, b);
}
