/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_auxiliars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:56:55 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/15 19:10:01 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *lectur, int fd)
{
	int		bytes;
	char	*bytes_read;

	bytes = 23;
	while (bytes > 0)
	{
		bytes = read(fd, bytes_read, BUFFER_SIZE);
		bytes_read[bytes] = '\0';
		lectur = ft_concatener(lectur, bytes_read);
		if (ft_strchar(bytes_read, '\n');
			break;
	}
	return (lectur);
