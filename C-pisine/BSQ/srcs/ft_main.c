/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:18:24 by seokhcho          #+#    #+#             */
/*   Updated: 2022/09/15 19:16:24 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_header.h"

void	handle_input(char *file_name)
{
	char	**splited_str;
	int		size;

	if (check_file_exist(file_name) != 0)
	{
		size = get_one_line(file_name);
		if (size != 0)
		{
			splited_str = split_one_line(size, file_name, &size);
			if (splited_str)
			{
				if (check_error(splited_str, size) == 0)
				{
					write(1, "map error\n", 10);
				}
			}
		}
	}
	return ;
}

void	handle_stdin(void)
{
	int		fd;
	char	buf[1];

	fd = open("file_name", O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd <= 0)
	{
		return ;
	}	
	while (read(0, buf, 1))
		write(fd, buf, 1);
	return ;
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		handle_stdin();
		handle_input("file_name");
	}
	else if (ac == 2)
	{
		handle_input(av[1]);
	}
	else if (ac >= 3)
	{
		while (i < ac)
		{
			handle_input(av[i]);
			if (i != (ac - 1))
				write(1, "\n", 1);
			i++;
		}
	}
	system("leaks bsq");
	return (0);
}
