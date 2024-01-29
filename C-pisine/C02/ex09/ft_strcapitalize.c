/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:09:22 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 20:32:51 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	count;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	count = 1;
	while (str[count])
	{
		if ('A' <= str[count] && str[count] <= 'Z')
			str[count] = str[count] - 'A' + 'a';
		if ('a' <= str[count] && str[count] <= 'z')
			if (!('a' <= str[count - 1] && str[count - 1] <= 'z'))
				if (!('A' <= str[count - 1] && str[count - 1] <= 'Z'))
					if (!('0' <= str[count - 1] && str[count - 1] <= '9'))
						str[count] = str[count] - 'a' + 'A';
		count++;
	}
	return (str);
}
