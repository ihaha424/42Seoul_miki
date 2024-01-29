/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:46:06 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/25 17:21:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	temp;

	temp = 0;
	if (str == NULL)
		return (temp);
	while (str[temp])
	{
		temp++;
	}
	return (temp);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*add;

	i = ft_strlen(src);
	add = (char *)malloc(sizeof(char) * (i + 1));
	if (!add)
		return (0);
	i = 0;
	while (src[i])
	{
		add[i] = src[i];
		i++;
	}
	add[i] = '\0';
	return (add);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ndst;
	unsigned char	*nsrc;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (ndst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (ndst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len1;
	size_t		len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, (char *)s1, len1);
	ft_memcpy(str + len1, (char *)s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size != 0 && dest != NULL)
	{
		while (count < size - 1 && src[count])
		{
			dest[count] = src[count];
			count++;
		}
	}
	dest[count] = '\0';
	count = 0;
	while (src[count])
	{
		count++;
	}
	return (count);
}
