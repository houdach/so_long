#include "map.h"
#include "get_next_line.h"

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}
int validate_map(int fd)
{
    int i;
    char *line;
    int arr[2];
    size_t len;
    size_t lens;

    arr[0] = 0;
    arr[1] = 0;
    fd = open("mapp.ber", O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
    {
        if (line[i] == '1')
            i++;
        else
            return (0);
    }
    lens = ft_strlen1(line);
    while ((line = get_next_line(fd)) != NULL)
    {
        len = ft_strlen1(line);
        if(len != lens)
            return (0);
        if (line[0] != '1' || line[len - 1] != '1')
            break ;
        i = 0;
        while (line[i])
        {
            if (line[i] == 'E' || line[i] == 'P')
            {
                if (line[i] == 'E')
                    arr[0] += 1;
                else if(line[i] == 'P')
                    arr[1] += 1;
                i++;
            }
            else 
                i++;
        }
    }
    if (arr[0] == 1 && arr[1] == 1)
    {
        return (1);
    }
    else
        return (0);
}

int read_map()
{
    
    char *line;
    int fd;
    int br;

    fd = open("mapp.ber", O_RDONLY);
    int flag;
    flag = validate_map(fd);
    br = 0;
    if (flag == 1)
    {
         while ((line = get_next_line(fd)) != NULL)
        {
            br += printf("%s", line);
            free(line);
        }
    }
    return (br);
}

int main()
{
    int cn;
    cn = read_map();
}