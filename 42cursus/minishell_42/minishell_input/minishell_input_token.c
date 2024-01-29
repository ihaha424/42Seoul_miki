/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_input_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:03:48 by dongmiki          #+#    #+#             */
/*   Updated: 2023/09/18 19:29:18 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	input_redirection(t_token *token, char **str, int *i, int *num)
{
	token->redirection[*num] = (char **)ft_malloc(sizeof(char *) * 3);
	token->redirection[*num][0] = str[*i];
	if (!str[(*i) + 1])
		error("bash: syntax error near unexpected token `newline'", 258);
	token->redirection[*num][1] = str[(*i) + 1];
	token->redirection[*num][2] = NULL;
	(*num)++;
	(*i)++;
}

static void	input_cmd(t_token *token, char **str, int i, int *num)
{
	token->cmd[*num] = str[i];
	(*num)++;
}

static void	input_token_second(t_token *token, char **str, \
int num_cmd, int num_redirect)
{
	int	i;

	token->redirection = (char ***)ft_malloc(sizeof(char **) * \
	(num_redirect + 1));
	token->redirection[num_redirect] = NULL;
	token->cmd = (char **)ft_malloc(sizeof(char *) * (num_cmd + 1));
	token->cmd[num_cmd] = NULL;
	i = -1;
	num_redirect = 0;
	num_cmd = 0;
	while (str[++i])
	{
		if (str[i][0] == '\0')
			continue ;
		if (!ft_strncmp(str[i], "<", 2))
			input_redirection(token, str, &i, &num_redirect);
		else if (!ft_strncmp(str[i], "<<", 3))
			input_redirection(token, str, &i, &num_redirect);
		else if (!ft_strncmp(str[i], ">", 2))
			input_redirection(token, str, &i, &num_redirect);
		else if (!ft_strncmp(str[i], ">>", 3))
			input_redirection(token, str, &i, &num_redirect);
		else
			input_cmd(token, str, i, &num_cmd);
	}
}

static void	input_token(t_token *token, char **str, int i)
{
	int	num_redirect;
	int	num_cmd;

	num_redirect = 0;
	num_cmd = 0;
	while (str[++i])
	{
		if (str[i][0] == '\0')
			continue ;
		if (!ft_strncmp(str[i], "<", 2))
			num_redirect++;
		else if (!ft_strncmp(str[i], "<<", 3))
			num_redirect++;
		else if (!ft_strncmp(str[i], ">", 2))
			num_redirect++;
		else if (!ft_strncmp(str[i], ">>", 3))
			num_redirect++;
		else
			num_cmd++;
	}
	num_cmd -= num_redirect;
	if (num_cmd < 0)
		error("bash: syntax error near unexpected token `newline'", 258);
	input_token_second(token, str, num_cmd, num_redirect);
}

void	make_token(t_minishell *minishell, char **str_split_pipe, char **envp)
{
	int		i;
	int		j;
	char	**temp;

	i = -1;
	while (str_split_pipe[++i])
		;
	minishell->token = (t_token *)ft_malloc(sizeof(t_token) * i);
	minishell->token_num = i;
	i = -1;
	while (str_split_pipe[++i])
	{
		temp = ft_split_quote(str_split_pipe[i], ' ', 0);
		free(str_split_pipe[i]);
		if (!temp)
			error("bash: system error(malloc fail)", 1);
		j = -1;
		while (temp[++j])
			temp[j] = quote_conversion(temp[j], envp, -1);
		input_token(&(minishell->token[i]), temp, -1);
		free(temp);
	}
}
