/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:59:30 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/05 22:34:49 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next(char *buffer)
{
	char	*new_buffer;
	int i;
	int j;

	i = 0;
	j = 0;
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
char *get_the_line(char *buffer)
{
	char *retu;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	retu = malloc(i + 2);
	if(!retu)
		return (NULL);
	ft_strncpy(retu, buffer, i);
	if (buffer[i] == '\n')
		retu[i++] = '\n';
	retu[i] = '\0';	
	return(retu);
}

char	*check_read(int fd, char *buffer)
{
	char	*temp = malloc(BUFFER_SIZE + 1);
	ssize_t	read_bytes;
	
	
	if (!temp)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && (read_bytes = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[read_bytes] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			break;
	}
	free(temp);
	return (buffer);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE >= INT_MAX)
		return (free(buffer), buffer = NULL);
	buffer = check_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_the_line(buffer);
	buffer = get_next(buffer);
	return(line);
}
