/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_auxiliars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:56:55 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/15 21:23:04 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *lectur, int fd, char *bytes_read)
{
	int bytes;

	bytes = 23;
	while (bytes > 0)
	{
		bytes = read(fd, bytes_read, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		bytes_read[bytes] = '\0';
		lectur = ft_concatener(lectur, bytes_read);
		if (ft_strchar(bytes_read, '\n');
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
