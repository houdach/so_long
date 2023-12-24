
#ifndef MAP_H
# define MAP_H
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int read_map();
int validate_map(int fd);
size_t	ft_strlen1(char *s);
#endif
