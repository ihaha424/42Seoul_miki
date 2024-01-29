/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:54:31 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/29 11:25:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	count;
	int	count2;

	count = -1;
	while (dest[++count])
	{	
	}
	count2 = -1;
	while (src[++count2])
	{
		dest[count] = src[count2];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
