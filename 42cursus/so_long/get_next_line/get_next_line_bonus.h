/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmiki <dongmiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 01:37:42 by dongmiki          #+#    #+#             */
/*   Updated: 2023/02/25 19:03:12 by dongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *src);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size);

#endif