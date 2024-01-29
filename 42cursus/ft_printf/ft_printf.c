/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:39 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/12 17:03:23 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(char const *s, va_list ap)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += printf_c(ap);
	else if (*s == 's')
		len += printf_s(ap);
	else if (*s == 'p')
		len += printf_p(ap);
	else if (*s == 'd')
		len += printf_di(ap);
	else if (*s == 'i')
		len += printf_di(ap);
	else if (*s == 'u')
		len += printf_u(ap);
	else if (*s == 'x')
		len += printf_x(ap);
	else if (*s == 'X')
		len += printf_bigx(ap);
	else if (*s == '%')
		len += printf_percent();
	return (len);
}

static int	print_value(char const *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += find_format(s, ap);
			s++;
		}
		else
		{
			len += write(1, s, 1);
			s++;
		}
	}
	return (len);
}

int	ft_printf(const	char *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = print_value(s, ap);
	va_end(ap);
	return (len);
}
