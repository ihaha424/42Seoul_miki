/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:42 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 19:37:23 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_stack *ab)
{
	t_node	*temp;
	int		index;

	index = 1;
	temp = ab->top_a;
	while (index < ab->size_a)
	{
		if (temp->key > temp->bottom->key)
			return (0);
		index++;
		temp = temp->bottom;
	}
	return (1);
}

static void	quick_sort(t_stack *ab, int max)
{
	int	index;

	index = ab->size_a;
	while (index-- > 0)
	{
		if (ab->top_a->key < (max / 3) && ab->top_a->key != max)
		{
			pb(ab, 1);
			rb(ab, 1);
		}
		else if (ab->top_a->key < (max / 3 * 2) && ab->top_a->key != max)
		{
			pb(ab, 1);
		}
		else
			ra(ab, 1);
	}
	while (ab->size_a > 1)
	{
		if (ab->top_a->key == max)
			ra(ab, 1);
		pb(ab, 1);
	}
	pb(ab, 1);
	greedy(ab);
}

static void	under_three(t_stack *ab, int max)
{
	if (check_sorting(ab))
		return ;
	if (ab->size_a == 1)
		return ;
	else if (ab->size_a == 2)
		sa(ab, 1);
	else if (ab->size_a == 3)
	{
		if (ab->top_a->key == max)
			ra(ab, 1);
		if (ab->top_a->bottom->key == max)
			rra(ab, 1);
		if (!check_sorting(ab))
			sa(ab, 1);
	}
}

static void	hard_coding(t_stack *ab)
{
	int		max;
	int		min;
	t_node	*temp;

	max = ft_max(ab);
	min = ft_min(ab);
	temp = ab->top_a;
	while (ab->size_b < 2)
	{
		if (temp->key == max || temp->key == min)
			pb(ab, 1);
		else
			ra(ab, 1);
		temp = ab->top_a;
	}
	max = ft_max(ab);
	under_three(ab, max);
	if (ab->top_b->key < ab->bottom_b->key)
		sb(ab, 1);
	pa(ab, 1);
	ra(ab, 1);
	pa(ab, 1);
}

void	ft_sort(t_stack *ab)
{
	int	max;

	if (check_sorting(ab))
		return ;
	max = ft_max(ab);
	if (ab->size_a < 4)
		under_three(ab, max);
	else if (ab->size_a == 4 || ab->size_a == 5)
		hard_coding(ab);
	else
		quick_sort(ab, max);
}
