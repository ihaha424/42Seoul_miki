/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:19:58 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/17 18:07:36 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *ab, int flag)
{
	if (ab->size_a < 2)
		return ;
	ab->top_a = ab->top_a->bottom;
	ab->bottom_a = ab->bottom_a->bottom;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *ab, int flag)
{
	if (ab->size_b < 2)
		return ;
	ab->top_b = ab->top_b->bottom;
	ab->bottom_b = ab->bottom_b->bottom;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack *ab, int flag)
{
	ra(ab, 0);
	rb(ab, 0);
	if (flag)
		write(1, "rr\n", 3);
}
