/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:26:02 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/08 23:33:07 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	count2;
	unsigned int	result;

	count = 0;
	while (dest[count])
		count++;
	count2 = 0;
	while (src[count2])
		count2++;
	result = count + count2;
	if (count >= size)
		return (count2 + size);
	count2 = 0;
	while (src[count2] && count + 1 < size)
	{
		dest[count] = src[count2];
		count++;
		count2++;
	}
	dest[count] = '\0';
	return (result);
}
