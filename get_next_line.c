/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:49:47 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/15 21:22:25 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd);
{
	static char		*lectur;
	char			*bytes_read;
	char			*line;
	bytes_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = read_line(lectur, fd, bytes_read);
	lectur = set_lectur(line);   

// while(mientras fd exista)
// tengo que ir leyendo linea por linea, ir aplicando calloc a cada linea para tener el espacio justo para escribirla y que no sobre espacio de memoria
//		while(str[i] != '\n' || str[i] != '\0')
//			count++;
//		tmp = calloc(sizeof(char) * BUFFER_SIZE + 1)

	if (!fd)
		return (NULL);





int main(void)
{
    static int contador = 0;
    contador++;
    printf("El valor del contador es: %d\n", contador);
	return (0);
}

