/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:05:07 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 17:52:32 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*add;

	i = 0;
	while (src[i])
		i++;
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
