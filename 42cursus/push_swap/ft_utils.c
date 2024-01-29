/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:57:58 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/17 17:44:13 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_stack *ab)
{
	int		max;
	int		index;
	t_node	*temp;

	index = 0;
	temp = ab ->top_a;
	max = temp->key;
	while (index < ab->size_a)
	{
		if (temp->key > max)
			max = temp->key;
		temp = temp->bottom;
		index++;
	}
	return (max);
}

int	ft_min(t_stack *ab)
{
	int		min;
	int		index;
	t_node	*temp;

	index = 0;
	temp = ab ->top_a;
	min = temp->key;
	while (index < ab->size_a)
	{
		if (temp->key < min)
			min = temp->key;
		temp = temp->bottom;
		index++;
	}
	return (min);
}

void	search(t_node **temp, int *num, int *index_a)
{
	*temp = (*temp)->bottom;
	(*num) = (*temp)->key;
	(*index_a)++;
}

void	free_split(char **split_word)
{
	int	index;

	index = -1;
	while (split_word[++index])
		free(split_word[index]);
	free(split_word);
}

int	check_duplicate(t_stack *ab)
{
	int		key;
	int		out;
	int		in;
	t_node	*temp;

	out = 0;
	temp = ab ->top_a;
	while (out < ab->size_a)
	{
		in = out + 1;
		key = temp->key;
		while (in < ab->size_a)
		{
			temp = temp->bottom;
			if (temp->key == key)
				return (0);
			in++;
		}
		in = out + 2;
		while (in-- > 0)
			temp = temp->bottom;
		out++;
	}
	return (1);
}
