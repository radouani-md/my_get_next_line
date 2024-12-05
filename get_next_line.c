/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:59:30 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/05 15:30:26 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next(char **buffer)
{
	char *retu;
	int i;
	int j;

	i = 0;
	j = 0;
	while (*buffer[i])
	{
		if (*buffer[i] == '\n')
			break ;
		i++;
	}
	retu = malloc(ft_strlen(*buffer) - i + 1);
	if(!retu)
		return (NULL);
	i++;
	while (*buffer[i] != '\0')
	{
		retu[j] = *buffer[i];
		j++;
	}
	retu[j] = '\0';
	free(*buffer);
	*buffer = retu;
	return(free(retu), retu = NULL, *buffer);
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
	retu = malloc(i + 1);
	if(!retu)
		return (NULL);
	while (i > j)
	{
		retu[j] = buffer[j];
		j++;
	}
	retu[j] = '\0';
	return(retu);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*buffer;
	ssize_t		readed_bytes;
	char		*line;

	temp = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || !temp)
		return (free(temp), free(buffer), buffer = NULL);
	readed_bytes = read(fd, temp[BUFFER_SIZE], BUFFER_SIZE);
	if (readed_bytes < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	temp[readed_bytes] = '\0';
	buffer = ft_strjoin(buffer, temp);
	if (!buffer)
		return(free(temp), NULL);
	line = get_the_line(buffer);
	buffer = get_next(&buffer);
	free(temp);
	return(line);
}
