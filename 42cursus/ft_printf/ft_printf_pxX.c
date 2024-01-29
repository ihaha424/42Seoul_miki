/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:32 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/12 22:14:10 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_check_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*convert_hex(unsigned long long arg, int ul)
{
	int		len;
	char	*temp;

	if (arg == 0)
		return (ft_strdup("0"));
	len = hex_check_len(arg);
	temp = malloc(sizeof(char) * len + 1);
	if (temp == NULL)
		return (0);
	temp[len] = '\0';
	len -= 1;
	while (len >= 0)
	{
		if (ul == 0)
			temp[len] = "0123456789abcdef"[arg % 16];
		if (ul == 1)
			temp[len] = "0123456789ABCDEF"[arg % 16];
		arg /= 16;
		len--;
	}
	return (temp);
}

int	printf_p(va_list ap)
{
	unsigned long long int	arg;
	int						len;
	char					*temp;

	len = 0;
	arg = va_arg(ap, size_t);
	len += write(1, "0x", 2);
	temp = convert_hex(arg, 0);
	len += ft_strlen(temp);
	write(1, temp, len - 2);
	free(temp);
	return (len);
}

int	printf_x(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, size_t);
	temp = convert_hex(arg, 0);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}

int	printf_bigx(va_list ap)
{
	unsigned int	arg;
	int				len;
	char			*temp;

	arg = va_arg(ap, size_t);
	temp = convert_hex(arg, 1);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}
