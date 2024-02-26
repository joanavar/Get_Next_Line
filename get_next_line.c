/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:47 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/26 18:29:05 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*double_free(char *ptr1, char *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (NULL);
}

static char	*read_line(char	*lectur, int fd)
{
	int		bytes;
	char	*bytes_read;

	bytes = 23;
	bytes_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bytes_read)
		return (NULL);
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
	new_line = ft_substring(lectur, 0, i + 1);
	if (!new_line)
		return (NULL);
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
		return (double_free(lectur, NULL));
	line = set_line(lectur);
	if (!line || line[0] == '\0')
		return (double_free(line, lectur));
	lectur = new_lectur(lectur, line);
	return (line);
}

// while(mientras fd exista)
// tengo que ir leyendo linea por linea, ir aplicando calloc a cada linea para tener el espacio justo para escribirla y que no sobre espacio de memoria
//		while(str[i] != '\n' || str[i] != '\0')
//			count++;
//		tmp = calloc(sizeof(char) * BUFFER_SIZE + 1)

/*int main(void)
{
    int fd = open("si.txt", O_RDONLY);
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
