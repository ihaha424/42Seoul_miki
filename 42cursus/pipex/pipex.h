/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:12:05 by dongmiki          #+#    #+#             */
/*   Updated: 2023/06/17 15:11:44 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "./get_next_line/get_next_line_bonus.h"

typedef struct s_arg
{
	int		infile;
	int		outfile;
	int		cmd_count;
	char	**cmd;
}	t_arg;

int		main(int ac, char *av[], char **envp);
void	cmd_start(t_arg *arg, char **envp, int index, char **av);
void	child_process(t_arg *arg, char **envp, char **av);
void	child_process_bonus(t_arg *arg, char **envp, int i, char **av);
void	parent_process(t_arg *arg, char **envp, char **av);
void	error(int flag, char *av);
void	here_doc(t_arg *arg);
void	final_process(t_arg *arg, char **envp, int i, char **av);
void	wait_all(void);
char	*find_path(char *cmd, char **envp);
char	*is_path(int i, char *cmd, char **paths);
t_arg	*arg_check(int ac, char **av);
t_arg	*free_malloc(t_arg *arg, int flag, char **av);

#endif