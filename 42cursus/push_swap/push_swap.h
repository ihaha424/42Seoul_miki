/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:05 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 20:25:10 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./Libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"

typedef struct s_node
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				key;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	int				size_a;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
	int				size_b;
}	t_stack;

int		main(int ac, char *av[]);
t_stack	*make_stack(int ac, char **av);
void	sa(t_stack *ab, int flag);
void	sb(t_stack *ab, int flag);
void	ss(t_stack *ab, int flag);
void	pa(t_stack *ab, int flag);
void	pb(t_stack *ab, int flag);
void	ra(t_stack *ab, int flag);
void	rb(t_stack *ab, int flag);
void	rr(t_stack *ab, int flag);
void	rra(t_stack *ab, int flag);
void	rrb(t_stack *ab, int flag);
void	rrr(t_stack *ab, int flag);
void	ft_sort(t_stack *ab);
void	greedy(t_stack *ab);
int		ft_max(t_stack *ab);
int		ft_min(t_stack *ab);
void	search(t_node **temp, int *num, int *index_a);
void	free_node(t_stack *stack, int index, int flag);
void	free_split(char **split_word);
int		check_duplicate(t_stack *ab);
int		check_sorting(t_stack *ab);
#endif