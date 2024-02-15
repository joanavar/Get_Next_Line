/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:52:13 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/15 18:34:14 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#  define FT_GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char *get_next_line(int fd);

#endif

