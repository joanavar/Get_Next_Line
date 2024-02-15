/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <joanavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:52:13 by joanavar          #+#    #+#             */
/*   Updated: 2024/02/15 21:23:02 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
#  define FT_GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_line(char *lectur, int fd, char *bytes_read);
size_t	ft_strlen(const char *str);
char	*ft_concatener(char const *s1, char const *s2);
char	*ft_strchar(const char *str, char c);
char	*ft_substring(char const *s, unsigned int start, size_t len);
char	*set_lectur(char *lectur);

#endif

