/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:30:27 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/15 20:37:27 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort1(int num, char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		temp;
	char	*a;

	i = 1;
	while (i < num)
	{
		temp = 0;
		a = tab[i];
		while (temp < i)
		{
			if ((*cmp)(tab[temp], tab[i]) > 0)
			{
				a = tab[temp];
				tab[temp] = tab[i];
				tab[i] = a;
			}
			temp++;
		}
		i++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	sort1 (size, tab, *cmp);
}
