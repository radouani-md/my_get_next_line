/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:15:49 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/05 22:26:25 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483647
#endif

char 	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char const *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);

#endif