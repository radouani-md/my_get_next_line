/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradouan <mradouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:47:10 by mradouan          #+#    #+#             */
/*   Updated: 2024/12/05 15:26:33 by mradouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i <= start)
		return (ft_strdup(""));
	if (start + len > i)
		len = i - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strncpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*str;

	i = 0;
	if (!src)
		return (NULL);
	str = malloc(ft_strlen(src) + 1);
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
		
	if (s1)
		ft_strncpy(result, s1, len1 + 1);
	if (s2)
		ft_strncpy(result + len1, s2, len2 + 1);
	free(s1);
	return (result);
}