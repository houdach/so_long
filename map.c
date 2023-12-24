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
    char *line1;
    char *line;
    int arr[2];
    size_t len;
    arr[0] = 0;
    arr[1] = 0;
    fd = open("mapp.ber", O_RDONLY);
    line1 = get_next_line(fd);
    i = 0;
    while (line1[i] != '\0')
    {
        if (line1[i] != '1')
            return(0);
        else
            i++;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        len = ft_strlen1(line);
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
    // line = get_next_line(fd);
    br = 0;
    int flag;
    //size_t len;
    flag = validate_map(fd);
    if (flag == 1)
    {
         while ((line = get_next_line(fd)) != NULL)
        {
            // len = ft_strlen1(line);
            // printf("%d\n", len);
            br += printf("%s", line);
            free(line);
            // fd = open("houda.txt", O_CREAT | O_RDONLY, 0777);
        }
    }
    return (br);
} line = get_next_line(fd);
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '1')
            return(0);
        else
            i++;
    }

int main()
{
    int cn;
    cn = read_map();
    //printf("%d\n", cn);
}