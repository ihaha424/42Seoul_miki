/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:44:58 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/11 10:47:19 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	sort(int num, char *argv[])
{
	int		i;
	int		temp;
	char	*a;

	i = 2;
	while (i < num)
	{
		temp = 1;
		a = argv[i];
		while (temp < i)
		{
			if (ft_strcmp(argv[temp], argv[i]) > 0)
			{
				a = argv[temp];
				argv[temp] = argv[i];
				argv[i] = a;
			}
			temp++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	temp;
	int	i;

	sort(argc, argv);
	temp = 1;
	while (temp < argc)
	{	
		i = 0;
		while (argv[temp][i])
		{
			write(1, &argv[temp][i], 1);
			i++;
		}
		write(1, "\n", 1);
		temp++;
	}
	return (0);
}
