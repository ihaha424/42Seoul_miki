/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:51:53 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/27 18:53:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (!('A' <= str[count] && str[count] <= 'Z'))
			return (0);
		count++;
	}
	return (1);
}
