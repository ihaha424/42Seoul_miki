/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:13:25 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 20:21:11 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_stack *stack, int index, int flag)
{
	t_node	*node;

	while (index > 0)
	{
		node = stack->top_a->bottom;
		free(stack->top_a);
		stack->top_a = node;
		index--;
	}
	free(stack);
	if (flag == 0)
		write(1, "Error\n", 6);
	exit(0);
}

static void	link_split_node(t_stack *stack, char *av, int *check)
{
	t_node	*node;
	char	**split_word;
	int		index;

	index = -1;
	split_word = ft_split(av, ' ');
	while (split_word[++index])
	{
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			free_node(stack, stack->size_a, 0);
		node->key = ft_atoi(split_word[index], check);
		if (!(*check))
		{
			free(node);
			free_node(stack, stack->size_a, 0);
		}
		stack->bottom_a->bottom = node;
		node->top = stack->bottom_a;
		stack->bottom_a = node;
		stack->size_a++;
	}
	free_split(split_word);
}

static int	split_key(char *av, t_stack *stack, int *check)
{
	int		index;

	index = 0;
	while (av[index])
	{
		if (av[index] == ' ')
		{
			link_split_node(stack, av, check);
			return (0);
		}
		index++;
	}
	return (1);
}

static int	linked_node(int ac, char **av, t_stack *stack, int *check)
{
	t_node	*node;
	int		index;

	index = 1;
	while (++index < ac)
	{
		if (!split_key(av[index], stack, check))
			continue ;
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			free_node(stack, stack->size_a, 0);
		node->key = ft_atoi(av[index], check);
		if (!(*check))
		{
			free(node);
			free_node(stack, stack->size_a, 0);
		}
		stack->bottom_a->bottom = node;
		node->top = stack->bottom_a;
		stack->bottom_a = node;
		stack->size_a++;
	}
	return (1);
}

t_stack	*make_stack(int ac, char **av)
{
	t_node	*node;
	t_stack	*stack;
	int		check;

	check = 1;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	stack->top_a = node;
	stack->bottom_a = node;
	stack->size_a = 1;
	if (split_key(av[1], stack, &check))
		node->key = ft_atoi(av[1], &check);
	else
	{
		stack->top_a = node->bottom;
		stack->size_a--;
		free(node);
	}
	if (linked_node(ac, av, stack, &check) < 0 || check == 0)
		return (NULL);
	return (stack);
}
