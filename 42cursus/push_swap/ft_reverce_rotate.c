/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverce_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:20:00 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/20 19:42:05 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *ab, int flag)
{
	if (ab->size_a < 2)
		return ;
	ab->top_a = ab->bottom_a;
	ab->bottom_a = ab->bottom_a->top;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *ab, int flag)
{
	if (ab->size_b < 2)
		return ;
	ab->top_b = ab->bottom_b;
	ab->bottom_b = ab->bottom_b->top;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *ab, int flag)
{
	rra(ab, 0);
	rrb(ab, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
