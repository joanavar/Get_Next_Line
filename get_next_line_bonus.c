/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:00:52 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/27 20:16:42 by joanavar         ###   ########.fr       */
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
	char	*tmp;

	bytes = 23;
	bytes_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bytes_read)
		return (double_free(&lectur[fd], NULL));
	while (bytes > 0)
	{
		bytes = read(fd, bytes_read, BUFFER_SIZE);
		if (bytes == -1)
			return (double_free(lectur, bytes_read));
		bytes_read[bytes] = '\0';
		tmp = lectur;
		lectur = ft_concatener(tmp, bytes_read);
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
		new_line = ft_substring(lectur,  0, i + 1);
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
	static char		*lectur[10240];
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!lectur[fd])
	{
		lectur[fd] = malloc(sizeof(char) * 1);
		if (!lectur[fd])
			return (NULL);
		lectur[fd][0] = '\0';
	}
	lectur[fd] = read_line(lectur[fd], fd);
	if (!lectur[fd])
		return (NULL);
	line = set_line(lectur[fd]);
	if (!line)
	{
		if (lectur[fd] != NULL)
			free(lectur[fd]);
		return (lectur[fd] = NULL, NULL);
	}
	lectur[fd] = new_lectur(lectur[fd], line);
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
