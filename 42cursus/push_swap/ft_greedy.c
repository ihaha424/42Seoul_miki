/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:37:18 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/20 20:06:03 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_a_location(t_stack *ab, int key)
{
	t_node	*temp;
	int		num;
	int		index_a;

	if (ab->size_a < 2)
		return (0);
	index_a = 0;
	temp = ab->top_a;
	num = temp->key;
	if (key < ft_min(ab))
		while (num != ft_min(ab))
			search(&temp, &num, &index_a);
	else
		while (!(num > key && temp->top->key < key))
			search(&temp, &num, &index_a);
	if (index_a >= (ab->size_a + 1) / 2)
			index_a = (ab->size_a - index_a) * -1;
	return (index_a);
}

static int	compare(int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		if (a < b)
			a = b;
	}
	else if (a <= 0 && b <= 0)
	{
		if (a > b)
			a = -b;
		else
			a = -a;
	}
	else if (a >= 0 && b < 0)
		a = a - b;
	else
		a = -a + b;
	return (a);
}

static void	min_rotation(t_stack *ab, int *a, int *b)
{
	int		count_a;
	int		count_b;
	int		index_b;
	int		key;
	t_node	*temp;

	index_b = -1;
	temp = ab->top_b;
	while (++index_b < ab->size_b)
	{
		key = temp->key;
		count_a = count_a_location(ab, key);
		if (index_b < (ab->size_b + 1) / 2)
			count_b = index_b;
		else
			count_b = (ab->size_b - index_b) * -1;
		if (index_b == 0 || (compare(count_a, count_b) < compare(*a, *b)))
		{
			*a = count_a;
			*b = count_b;
		}
		temp = temp->bottom;
	}
}

static void	rotation(t_stack *ab, int a, int b)
{
	while (a > 0 && b > 0)
	{
		rr(ab, 1);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		rrr(ab, 1);
		a++;
		b++;
	}
	while (a && a > 0 && a-- > 0)
		ra(ab, 1);
	while (a && a < 0 && a++ < 0)
		rra(ab, 1);
	while (b && b > 0 && b-- > 0)
		rb(ab, 1);
	while (b && b < 0 && b++ < 0)
		rrb(ab, 1);
}

void	greedy(t_stack *ab)
{
	int		count_a;
	int		count_b;
	t_node	*temp;

	while (ab->size_b)
	{
		count_a = 0;
		count_b = 0;
		min_rotation(ab, &count_a, &count_b);
		rotation(ab, count_a, count_b);
		pa(ab, 1);
	}
	count_b = ft_min(ab);
	count_a = 0;
	temp = ab->top_a;
	while (temp->key != count_b)
	{
		temp = temp->bottom;
		count_a++;
	}
	if (count_a >= (ab->size_a + 1) / 2)
			count_a = (ab->size_a - count_a) * -1;
	rotation(ab, count_a, 0);
}
