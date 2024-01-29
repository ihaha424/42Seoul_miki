/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:54:54 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/13 00:57:44 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	total_len(int size, char **strs)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

void	connect(char **strs, char *sep, int size, char *add)
{
	int	i;
	int	j;
	int	add_i;

	i = 0;
	add_i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			add[add_i++] = strs[i][j++];
		i++;
		j = 0;
		while (sep[j] && i < size)
			add[add_i++] = sep[j++];
	}
	add[add_i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	int		s_len;
	char	*add;

	t_len = total_len(size, strs);
	if (size == 0)
	{	
		add = (char *)malloc(sizeof(char) * 1);
		add[0] = '\0';
		return (add);
	}
	s_len = 0;
	while (sep[s_len])
		s_len++;
	add = (char *)malloc(sizeof(char) * (1 + t_len + (s_len * size - 1)));
	connect(strs, sep, size, add);
	return (add);
}
