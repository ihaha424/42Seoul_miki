/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:17:33 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 20:24:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_instruction(t_stack *ab, char *instruction, int *size)
{
	if (!ft_strncmp(instruction, "sa\n", *size))
		sa(ab, 0);
	else if (!ft_strncmp(instruction, "sb\n", *size))
		sb(ab, 0);
	else if (!ft_strncmp(instruction, "ss\n", *size))
		ss(ab, 0);
	else if (!ft_strncmp(instruction, "pa\n", *size))
		pa(ab, 0);
	else if (!ft_strncmp(instruction, "pb\n", *size))
		pb(ab, 0);
	else if (!ft_strncmp(instruction, "ra\n", *size))
		ra(ab, 0);
	else if (!ft_strncmp(instruction, "rb\n", *size))
		rb(ab, 0);
	else if (!ft_strncmp(instruction, "rr\n", *size))
		rr(ab, 0);
	else if (!ft_strncmp(instruction, "rra\n", *size))
		rra(ab, 0);
	else if (!ft_strncmp(instruction, "rrb\n", *size))
		rrb(ab, 0);
	else if (!ft_strncmp(instruction, "rrr\n", *size))
		rrr(ab, 0);
	else
		(*size) = -1;
}

static void	return_value(char **instruction, int flag)
{
	if (flag == 1)
		write(1, "OK\n", 3);
	else if (flag == 2)
		write(1, "Error\n", 6);
	else
		write(1, "KO\n", 3);
	if (*instruction)
		free(*instruction);
}

static void	read_instruction(t_stack *ab)
{
	char	*instruction;
	int		size;

	while (1)
	{
		instruction = get_next_line(0);
		if (!instruction)
			break ;
		size = ft_strlen(instruction);
		ft_instruction(ab, instruction, &size);
		if (size == -1)
			return (return_value(&instruction, 2));
		free(instruction);
	}
	if (check_sorting(ab) && ab->size_b == 0)
		return (return_value(&instruction, 1));
	return (return_value(&instruction, 0));
}

int	main(int ac, char *av[])
{
	t_stack	*ab;

	if (ac < 2)
	{
		return (-1);
	}
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
		read_instruction(ab);
	else
		write(1, "Error\n", 6);
	free_node(ab, ab->size_a, 1);
}
