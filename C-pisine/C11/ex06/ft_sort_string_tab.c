/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:12:29 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/12 16:32:08 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	temp;

	temp = 0;
	while (s1[temp] && s2[temp])
	{
		if (s1[temp] < s2[temp])
			return (-1);
		if (s1[temp] > s2[temp])
			return (1);
		temp++;
	}
	if (s1[temp] == '\0')
	{
		if (s2[temp] == '\0')
			return (0);
		else
			return (-1);
	}
	return (1);
}

void	sort(int num, char **tab)
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
			if (ft_strcmp(tab[temp], tab[i]) > 0)
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

void	ft_sort_string_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	sort(size, tab);
}
