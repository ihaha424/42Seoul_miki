/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:29:21 by dongmiki          #+#    #+#             */
/*   Updated: 2022/09/09 02:22:15 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_board(int col, int*board)
{
	int	temp;
	int	checkrow;
	int	checkcol;

	temp = 0;
	while (temp < col)
	{
		checkrow = board[temp] - board[col];
		checkcol = temp - col;
		if (checkrow == 0)
			return (0);
		else if (checkrow == checkcol)
			return (0);
		else if (checkrow == -checkcol)
			return (0);
		temp++;
	}
	return (1);
}

void	make_board(int col, int*board, int*answer)
{
	int		row;
	int		i;
	char	c;

	row = -1;
	i = -1;
	while (++row <= 9)
	{
		board[col] = row;
		if (check_board(col, board) == 1)
		{
			if (col < 9)
				make_board(col + 1, board, answer);
			else
			{
				while (++i <= 9)
				{
					c = board[i] + 48;
					write(1, &c, 1);
				}
				write(1, "\n", 1);
				*answer += 1;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	answer;

	i = 0;
	answer = 0;
	while (i <= 9)
	{
		board[i] = 0;
		i++;
	}
	make_board(0, board, &answer);
	return (answer);
}
