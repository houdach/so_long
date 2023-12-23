#include "map.h"
#include "get_next_line.h"

ssize_t read_map()
{
    
    char *line;
    int fd;
    fd = open("maps.ber", O_RDONLY);
    // line = get_next_line(fd);
    while ((line = get_next_line(fd))!= NULL )
	{
		ft_printf("%s", line);
		free(line);
		// fd = open("houda.txt", O_CREAT | O_RDONLY, 0777);
	}
}
// int validate_map()
// {

// }
int main()
{
}