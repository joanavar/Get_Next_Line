/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:11:13 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/26 18:29:02 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while  (str[i])
		i++;
	return (i);
}

char	*ft_concatener(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char)  * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];	
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchar(char *str, char c)
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
char	*ft_substring(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len && s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
char	*ft_strdup(char *s1)
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
