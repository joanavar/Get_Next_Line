/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:11:13 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/22 20:47:46 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while  (str[i])
		i++;
	return (i);
}

char	*ft_concatener(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];	
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchar(const char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lenchar;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	lenchar = ft_strlen(s);
	if (lenchar - start <= len)
		str = malloc((lenchar - start) + 1);
	else
		str = malloc(len + 1);
	if (str != NULL)
	{
		while (j < len && s[i] != '\0')
		{
			str[j] = s[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	return (str);
}
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
