/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:51:25 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/12 16:55:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./Libft/libft.h"

int	ft_printf(char const *s, ...);
int	printf_c(va_list ap);
int	printf_s(va_list ap);
int	printf_p(va_list ap);
int	printf_di(va_list ap);
int	printf_u(va_list ap);
int	printf_x(va_list ap);
int	printf_bigx(va_list ap);
int	printf_percent(void);

#endif