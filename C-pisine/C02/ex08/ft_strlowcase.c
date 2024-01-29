/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:07:12 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 20:12:09 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('A' <= str[count] && str[count] <= 'Z')
			str[count] = str[count] - 'A' + 'a';
		count++;
	}
	return (str);
}
