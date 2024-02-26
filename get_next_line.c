/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:47 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/26 19:52:27 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*double_free(char *ptr1, char *ptr2)
{
	if (ptr1 != NULL)
	{
		free(ptr1);
		ptr1 = NULL;
	}
	if (ptr2 != NULL)
	{
		free(ptr2);
		ptr2 = NULL;
	}
	return (NULL);
}

static char	*read_line(char	*lectur, int fd)
{
	int		bytes;
	char	*bytes_read;

	bytes = 23;
	bytes_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bytes_read)
		return (double_free(lectur, NULL));
	while (bytes > 0)
	{
		bytes = read(fd, bytes_read, BUFFER_SIZE);
		if (bytes == -1)
			return (double_free(lectur, bytes_read));
		bytes_read[bytes] = '\0';
		lectur = ft_concatener(lectur, bytes_read);
		if (!lectur || lectur[0] == '\0')
			return (double_free(bytes_read, lectur));
		if (ft_strchar(bytes_read, '\n'))
			break ;
	}
	free(bytes_read);
	return (lectur);
}

static char	*set_line(char *lectur)
{
	char	*new_line;
	int		i;

	i = 0;
	while (lectur[i] != '\n' && lectur[i] != '\0')
		i++;
	if (lectur[i] == '\n')
		new_line = ft_substring(lectur, 0, i + 1);
	else
		new_line = ft_substring(lectur, 0, i);
	if (!new_line)
		return (NULL);
	if (new_line[0] == '\0')
		return (double_free(new_line, NULL));
	return (new_line);
}

static char	*new_lectur(char *lectur, char *line)
{
	char	*aux;
	char	*new_buf;
	int		len;

	len = ft_strlen(lectur) - ft_strlen(line);
	aux = ft_strchar(lectur, '\n');
	new_buf = ft_substring(aux, 1, len);
	if (!new_buf)
		return (double_free(lectur, NULL));
	free(lectur);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static char		*lectur;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!lectur)
	{
		lectur = malloc(sizeof(char) * 1);
		if (!lectur)
			return (NULL);
		lectur[0] = '\0';
	}
	lectur = read_line(lectur, fd);
	if (!lectur)
		return (NULL);
	line = set_line(lectur);
	if (!line)
	{
		if (lectur != NULL)
			free(lectur);
		return (lectur = NULL, NULL);
	}
	lectur = new_lectur(lectur, line);
	return (line);
}
/*
int main(void)
{
    int fd = open("1char.txt", O_RDONLY);
 	int i = 0;
 	char *si = get_next_line(fd);
 	while (si)
 	{
 		printf("la linea numero %d es: %s", i, si);
 		i++;
		free(si);
 		si = get_next_line(fd);
 	}
 	close(fd);
}*/
