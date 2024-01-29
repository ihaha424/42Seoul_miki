/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:02:08 by dongmiki          #+#    #+#             */
/*   Updated: 2023/01/31 14:11:28 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fp;
	char	*sss; 

	fp = open("./txt.txt", O_RDONLY);
	for (int i = 0; i > -1 ; i++){
		sss = get_next_line(1);
		printf("%d.%s",i + 1, sss);
		if(sss[0] == '1')
		{
			break;
		}
	}
	return (1);
}
