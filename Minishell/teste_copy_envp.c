#include <stdio.h>
#include <stdlib.h>

int  count_strs(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != NULL)
     i++;
    return (i);
}

char **copy_envp(char **envp)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = 0;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
    while (i < amount_strs)
    {
        cpy_envp[i] = ft_strdup(envp[i]);
        i++;
    }
    return (cpy_envp);
}