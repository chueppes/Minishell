#include "../.././includes/minishell.h"

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
    cpy_envp[i] = NULL;
    return (cpy_envp);
}

void print_commands(t_commands *temp)
{
    while (temp)
    {
        printf("%s\n%d\n", temp->cmd, temp->token);
        temp = temp->next;
    }
}

void print_exec(t_exec *temp)
{
    while (temp)
    {
        printf("%s\n", temp->aux);
        temp = temp->next;
    }
}