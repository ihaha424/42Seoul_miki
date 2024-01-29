/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:31 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/30 18:06:06 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	count;
	int	count2;

	count = -1;
	while (dest[++count])
	{	
	}
	count2 = -1;
	while (src[++count2] && (unsigned)count2 < nb)
	{
		dest[count] = src[count2];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
