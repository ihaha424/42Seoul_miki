/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:58:21 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 20:05:52 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('a' <= str[count] && str[count] <= 'z')
			str[count] = str[count] - 'a' + 'A';
		count++;
	}
	return (str);
}
