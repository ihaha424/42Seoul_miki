/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:58:43 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/13 18:31:48 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*ab;

	if (ac < 2)
		return (-1);
	ab = make_stack(ac, av);
	if (!ab)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	ab->top_a->top = ab->bottom_a;
	ab->bottom_a->bottom = ab->top_a;
	ab->top_b = NULL;
	ab->bottom_b = NULL;
	ab->size_b = 0;
	if (check_duplicate(ab))
		ft_sort(ab);
	else
		write(1, "Error\n", 6);
	free_node(ab, ab->size_a, 1);
}
