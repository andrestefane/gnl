/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astefane <astefane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:25:54 by astefane          #+#    #+#             */
/*   Updated: 2024/05/30 15:35:42 by astefane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_cleanline(char *str)
{
	char			*newstring;
	char			*character;
	unsigned int	len;

	character = ft_strchr(str, '\n');
	if (!character)
	{
		newstring = NULL;
		return (ft_free(&str));
	}
	else
		len = (unsigned int)(character - str) + 1;
	if (!str[len])
		return (ft_free(&str));
	newstring = ft_substr(str, len, ft_strlen(str) - len);
	if (!newstring)
		return (NULL);
	ft_free(&str);
	return (newstring);
}

char	*ft_get_line(char *str)
{
	char			*line;
	char			*character;
	size_t			len;

	if (!str)
		return (NULL);
	character = ft_strchr(str, '\n');
	len = (size_t)(character - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_reading(int fd, char *str)
{
	char		*buffer;
	ssize_t		bytes_read;

	if (BUFFER_SIZE < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&str));
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
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str && !ft_strchr(str, '\n')) || !str)
		str = ft_reading(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (ft_free(&str));
	str = ft_cleanline(str);
	return (line);
}
// Función principal

/* int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
