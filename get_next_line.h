/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchouai <hchouai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:32:55 by hchouai           #+#    #+#             */
/*   Updated: 2023/12/24 15:42:24 by hchouai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strchr( char *s, int c);
char	*ft_strdup( char *src);
size_t	ft_strlen(char *s);
char	*ft_substr(char  *s, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_line_buffer(int fd, char *remainder, char *buffer);
char	*set_remainder(char *line_buffer);
char	*get_next_line(int fd);

#endif
