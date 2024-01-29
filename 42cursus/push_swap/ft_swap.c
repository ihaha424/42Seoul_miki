/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:18:37 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/17 18:08:02 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *ab, int flag)
{
	int	temp;

	if (ab->size_a < 2)
		return ;
	temp = ab->top_a->key;
	ab->top_a->key = ab->top_a->bottom->key;
	ab->top_a->bottom->key = temp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *ab, int flag)
{
	int	temp;

	if (ab->size_b < 2)
		return ;
	temp = ab->top_b->key;
	ab->top_b->key = ab->top_b->bottom->key;
	ab->top_b->bottom->key = temp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *ab, int flag)
{
	sa(ab, 0);
	sb(ab, 0);
	if (flag)
		write(1, "ss\n", 3);
}
