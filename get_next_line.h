/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:52:13 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/13 15:37:20 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#  define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char *get_next_line(int fd);

#endif

