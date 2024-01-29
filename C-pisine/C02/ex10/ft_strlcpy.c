/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:12:16 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/30 22:52:05 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	if (size != 0)
	{
		while (count < size - 1 && src[count])
		{
			dest[count] = src[count];
			count++;
		}
		while (count < size)
		{
			dest[count] = '\0';
			count++;
		}
	}
	count = 0;
	while (src[count])
	{
		count++;
	}
	return (count);
}
