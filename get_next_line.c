/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:59:30 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/07 23:30:32 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_read(int fd, char *buffer)
{
	char	*temp;
	char	*joined;
	ssize_t	read_bytes;

	if (BUFFER_SIZE >= INT_MAX)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	read_bytes = read(fd, temp, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		temp[read_bytes] = '\0';
		joined = ft_strjoin(buffer, temp);
		if (!joined)
			return (free(temp), free(buffer), NULL);
		free(buffer);
		buffer = joined;
		if (!buffer || ft_strchr(buffer, '\n'))
			break ;
		read_bytes = read(fd, temp, BUFFER_SIZE);
	}
	free(temp);
	return (buffer);
}

char	*get_next(char *buffer)
{
	char	*new_buffer;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
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
	char	*retu;
	int		i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	retu = malloc(i + 2);
	if (!retu)
		return (NULL);
	ft_strncpy(retu, buffer, i);
	if (buffer[i] == '\n')
		retu[i++] = '\n';
	retu[i] = '\0';
	return (retu);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = check_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_the_line(buffer);
	buffer = get_next(buffer);
	return (line);
}
