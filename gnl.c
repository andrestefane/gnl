/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:54:16 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 10:54:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char    *ft_cleanline(char *str)
{
    char    *newstring;
    char    *character;
    int     len;

    character = ft_strchr(str, '\n');
    if (!character)
    {
        newstring = 0;
        free (&str);
        return (0);
    }
    else
        len = (character - str) + 1;
    if (!str[len])
    {
        free (&str);
        return (0);
    }
    newstring = ft_substr(str, len, ft_strlen(str) - len);
    if (!newstring)
        return (0);
    free (&str);
    return (newstring);
    
}
char    *ft_get_line(char *str)
{
    char    *line;
    char    *character;
    int     len;

    character = ft_strchr(str, '\n');
    len = (character - str) + 1;
    line = ft_substr(str, 0, len);
    if (!line)
        return (0);
    return (line);
}

char    *ft_reading(int fd, char *str)
{
    char    *buffer;
    int     bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        free (&str);
    bytes_read = 1;
    buffer[0] = '\0';
    while (!ft_strchr(buffer, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0';
            str = ft_strjoin(str, buffer);
        }
    }
    free (buffer);
    if (bytes_read == -1)
        free (&str);
    return (str);
}

char	*get_next_line(int fd)
{
    char *str;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    if ((str && !ft_strchr(str, '\n')) || !str)
        str = ft_reading(fd , str);
    if (!str)
        return (0);
    line = ft_lookline(str);
    if (!line)
        free (&str);
    str = ft_cleanline(str);
    return (line);
}