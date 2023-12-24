#include "map.h"
#include "get_next_line.h"

int validate_map(int fd)
{
    int i;
    char *line;
    int arr[2];
    arr[0] = 0;
    arr[1] = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        i = 0;
        while (line[i])
        {
            if (line[i] == 'E' || line[i] == 'P')
            {
                if (line[i] == 'E')
                    arr[0] += 1;
                if(line[i] == 'P')
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
    flag = validate_map(fd);
    if (flag == 1)
    {
         while ((line = get_next_line(fd))!= NULL )
        {
            br += printf("%s", line);
            free(line);
            // fd = open("houda.txt", O_CREAT | O_RDONLY, 0777);
        }
    }
    return (br);
}

int main()
{
    int cn;
    cn = read_map();
    //printf("%d\n", cn);
}