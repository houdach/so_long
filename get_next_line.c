/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchouai <hchouai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:32:38 by hchouai           #+#    #+#             */
/*   Updated: 2023/12/16 18:05:54 by hchouai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_remainder(char *line_buffer)
{
	ssize_t	i;
	char	*remainder;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	remainder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*remainder == 0)
	{
		free (remainder);
		return (NULL);
	}
	line_buffer[i + 1] = '\0';
	return (remainder);
}

char	*fill_line_buffer(int fd, char *remainder, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!remainder)
			remainder = (ft_strdup(""));
		tmp = remainder;
		remainder = ft_strjoin(tmp, buffer);
		free (tmp);
		if (ft_strchr(buffer, 10))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder);
		free(buffer);
		remainder = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, remainder, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remainder = set_remainder(line);
	return (line);
}
// #include <stdio.h>
// #include <time.h>
// int main()
// {
//     int fd;
// 	int fd2;	
//     fd = open("hdd.txt", O_CREAT | O_RDWR);
//      //write (fd, "\n\n\n\n\n\n\n\n\n\n\n", 12);
// 	 //close(fd);
// 	// fd2 = open("houda.txt", O_CREAT | O_RDWR, 0777);
//     //  write (fd2, "hello\nworldk\n", 13);
// 	//  close(fd2);
// 	//fd = open("hdd.txt", O_RDONLY);
// 	//fd2 = open("houda.txt", O_RDONLY);
// 	char *line ;
// 	//line = get_next_line(fd);
// 	// char * line3 = get_next_line(fd2);
// 	// char *line2 = get_next_line(fd);
// 	// char *line4 = get_next_line(fd2);
// 	// char *line5 = get_next_line(fd);
// 	//printf("%s", line);
// 	// printf("%s", line3);
// 	// printf("%s", line2);
// 	// printf("%s", line4);
// 	// printf("%s", line5);
// 	while ((line = get_next_line(fd))!= NULL )
// 	{
// 		printf("%s", line);
// 		free(line);
// 		// fd = open("houda.txt", O_CREAT | O_RDONLY, 0777);
// 	}
// 	//line = get_next_line(-1);
// 	//printf("%s", line);
// 	 close(fd);
// 	  printf("Execution time: %f seconds\n", 
//(double)(clock()) / CLOCKS_PER_SEC);
// 	system("leaks a.out");
//    return 0;
// }