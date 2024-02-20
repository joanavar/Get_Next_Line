/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:47 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/20 19:59:41 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char	*lectur, int fd, char *bytes_read)
{
	int bytes;

	bytes = 23;
	while (bytes > 0)
	{
		bytes_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		bytes_read[0] = '\0';
		bytes = read(fd, bytes_read, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		bytes_read[bytes] = '\0';
		lectur = ft_concatener(lectur, bytes_read);
		if (ft_strchar(bytes_read, '\n'))
				break;
	}
	return (lectur);
}

char	*set_lectur(char *lectur)
{
	char	*new_lectur;
	int		i;

	i = 0;
	while (lectur[i] != '\n' && lectur[i] != '\0')
		i++;
	new_lectur = ft_substring(lectur, i + 1, ft_strlen(lectur) - 1);
	lectur[i + 1] = 0;
	return (new_lectur);
}
/*
char	*double_free(char *ptr1, char *ptr2)
{
	if (ptr1 || *ptr1)
	{
		*ptr1 = NULL;
		free(ptr1);
	}
	if (ptr2 || *ptr2)
	{
		*ptr2 = NULL;
		free(ptr2);
	}
	return (NULL);

}
*/
char *get_next_line(int fd)
{
	static char		*lectur;
	char			*bytes_read;
	char			*line;
	if (!fd || BUFFER_SIZE > 0)
		return (NULL);
	printf("hola");
	bytes_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = read_line(lectur, fd, bytes_read);
	//if (!line)
	//	return (double_free(lectur, bytes_read))
	lectur = set_lectur(line);
	printf("%s", lectur);	
return (lectur);
}

// while(mientras fd exista)
// tengo que ir leyendo linea por linea, ir aplicando calloc a cada linea para tener el espacio justo para escribirla y que no sobre espacio de memoria
//		while(str[i] != '\n' || str[i] != '\0')
//			count++;
//		tmp = calloc(sizeof(char) * BUFFER_SIZE + 1)

int main(void)
{
    int fd = open("tester.txt", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
}	

