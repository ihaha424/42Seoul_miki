/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:20:03 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/17 18:07:06 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_utils(t_stack *ab, t_node *temp, int flag)
{
	if (ab->size_a == 0)
	{
		ab->top_a = temp;
		ab->bottom_a = temp;
		temp->top = NULL;
		temp->bottom = NULL;
	}
	else
	{
		temp->top = ab->bottom_a;
		temp->bottom = ab->top_a;
		ab->top_a->top = temp;
		ab->bottom_a->bottom = temp;
		ab->top_a = temp;
	}
	ab->size_b--;
	ab->size_a++;
	if (flag)
		write(1, "pa\n", 3);
}

void	pa(t_stack *ab, int flag)
{
	t_node	*temp;

	if (ab->size_b == 0)
		return ;
	else if (ab->size_b == 1)
	{
		temp = ab->top_b;
		ab->top_b = NULL;
		ab->bottom_b = NULL;
	}
	else if (ab->size_b == 2)
	{
		temp = ab->top_b;
		ab->top_b = ab->top_b->bottom;
		ab->top_b->top = NULL;
		ab->bottom_b->bottom = NULL;
	}
	else
	{
		temp = ab->top_b;
		ab->top_b = ab->top_b->bottom;
		ab->top_b->top = ab->bottom_b;
		ab->bottom_b->bottom = ab->top_b;
	}
	pa_utils(ab, temp, flag);
}

static void	pb_utils(t_stack *ab, t_node *temp, int flag)
{
	if (ab->size_b == 0)
	{
		ab->top_b = temp;
		ab->bottom_b = temp;
		temp->top = NULL;
		temp->bottom = NULL;
	}
	else
	{
		temp->top = ab->bottom_b;
		temp->bottom = ab->top_b;
		ab->top_b->top = temp;
		ab->bottom_b->bottom = temp;
		ab->top_b = temp;
	}
	ab->size_a--;
	ab->size_b++;
	if (flag)
		write(1, "pb\n", 3);
}

void	pb(t_stack *ab, int flag)
{
	t_node	*temp;

	if (ab->size_a == 0)
		return ;
	else if (ab->size_a == 1)
	{
		temp = ab->top_a;
		ab->top_a = NULL;
		ab->bottom_a = NULL;
	}
	else if (ab->size_a == 2)
	{
		temp = ab->top_a;
		ab->top_a = ab->top_a->bottom;
		ab->top_a->top = NULL;
		ab->bottom_a->bottom = NULL;
	}
	else
	{
		temp = ab->top_a;
		ab->top_a = ab->top_a->bottom;
		ab->top_a->top = ab->bottom_a;
		ab->bottom_a->bottom = ab->top_a;
	}
	pb_utils(ab, temp, flag);
}
