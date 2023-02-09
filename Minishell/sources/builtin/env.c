#include "../includes/minishell.h"

void    do_env(t_data *envp)
{
    int i;

    i = -1;
    while (envp->minishell_envp[++i])
    {
        printf("%s\n", minishell_envp[i]);
    }
}