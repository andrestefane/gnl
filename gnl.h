/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:54:28 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 10:54:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int	    ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_reading(int fd, char *str);
char    *ft_get_line(char *str);
char    *ft_cleanline(char *str);

#endif