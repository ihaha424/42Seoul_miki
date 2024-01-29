/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:14:24 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/07 20:28:42 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp1(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] && s2[count] && s1[count] == s2[count] && count < n)
		count++;
	if (count == n)
		return ((unsigned char)s1[count - 1] - (unsigned char)s2[count - 1]);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	if (to_find[count2] == '\0')
		return (&str[0]);
	while (to_find[count2])
		count2++;
	while (str[count])
	{
		if (ft_strncmp1(&str[count], to_find, count2) == 0)
			return (&str[count]);
		count++;
	}
	return (0);
}
