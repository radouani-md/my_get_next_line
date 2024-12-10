/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:23:42 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/10 16:47:37 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next(char *static_v)
{
	char	*new_buffer;
	int		i;

	i = 0;
	while (static_v[i])
	{
		if (static_v[i] == '\n')
			break ;
		i++;
	}
	if (!static_v[i])
		return (free(static_v), NULL);
	new_buffer = ft_strdup(static_v + i + 1);
	free(static_v);
	return (new_buffer);
}

char	*get_the_line(char *static_v)
{
	int		i;
	char	*str;

	i = 0;
	if (!static_v[i])
		return (NULL);
	while (static_v[i] && static_v[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (static_v[i] && static_v[i] != '\n')
	{
		str[i] = static_v[i];
		i++;
	}
	if (static_v[i] == '\n')
	{
		str[i] = static_v[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*static_v;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (static_v)
			free(static_v);
		static_v = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	static_v = check_read(fd, buffer, static_v);
	free(buffer);
	if (!static_v)
		return (free(static_v), NULL);
	line = get_the_line(static_v);
	static_v = get_next(static_v);
	return (line);
}
