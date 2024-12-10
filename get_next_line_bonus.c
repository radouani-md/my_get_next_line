/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:59:30 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/10 16:48:39 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*check_read(int fd, char *buffer, char *static_v)
{
	char	*joined;
	ssize_t	read_bytes;

	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(static_v, buffer);
		if (!joined)
			return (free(buffer), free(static_v), NULL);
		static_v = joined;
		if (ft_strchr(static_v, '\n'))
			break ;
	}
	return (static_v);
}

char	*get_next(char *buffer)
{
	char	*new_buffer;
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_strdup(buffer + i + 1);
	free(buffer);
	return (new_buffer);
}

char	*get_the_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*static_v[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX || read(fd, NULL, 0) < 0)
	{
		if (static_v[fd])
			free(static_v[fd]);
		static_v[fd] = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	static_v[fd] = check_read(fd, buffer, static_v[fd]);
	free(buffer);
	if (!static_v[fd])
		return (free(static_v[fd]), NULL);
	line = get_the_line(static_v[fd]);
	static_v[fd] = get_next(static_v[fd]);
	return (line);
}
