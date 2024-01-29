/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:10:27 by dongmiki          #+#    #+#             */
/*   Updated: 2022/08/30 17:07:37 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	count;

	count = -1;
	while (str[++count])
	{
		if ('a' <= str[count] && str[count] <= 'z')
			continue ;
		else if ('A' <= str[count] && str[count] <= 'Z')
			continue ;
		return (0);
	}
	return (1);
}
