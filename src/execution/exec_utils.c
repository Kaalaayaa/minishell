#include "../includes/minishell.h"

void    ft_trim_end(char *arr, char c)
{
    size_t  len;

    if (!arr)
        return ;

    len = ft_strlen(arr);
    if (len > 0 && arr[len - 1] == c)
            arr[len-1] = '\0';
    
}