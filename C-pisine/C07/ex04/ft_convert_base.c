/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:32:42 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/14 02:52:05 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_up(char *base)
{
	int	i;
	int	j;

	if (length(base) <= 1)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == 127 || base[i] <= 32)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	from_len_to(int from_len, int to_len)
{
	int	count;

	count = 1;
	if (from_len < 0)
		from_len *= -1;
	while (from_len >= to_len)
	{
		from_len = from_len / to_len;
		count++;
	}
	return (count);
}

void	ft_putnbr_base(int nbr, char *base, char *string, int count)
{
	int			base_length;
	long long	temp;
	int			st_i;

	st_i = 0;
	if (check_up(base))
		return ;
	temp = nbr;
	base_length = length(base);
	if (temp < 0)
	{	
		temp *= -1;
		string[0] = '-';
	}
	if (temp < base_length)
		string[count] = base[temp];
	else
	{
		string[count] = base[temp % base_length];
		ft_putnbr_base(temp / base_length, base, string, --count);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_10;
	int		len;
	char	*string;

	if (check_up(base_from) || check_up(base_to))
		return (0);
	base_10 = ft_atoi_base(nbr, base_from);
	len = from_len_to(base_10, length(base_to));
	if (base_10 < 0)
		len++;
	string = (char *)malloc(sizeof(char) * (len + 1));
	ft_putnbr_base(base_10, base_to, string, len - 1);
	string[len] = 0;
	return (string);
}
