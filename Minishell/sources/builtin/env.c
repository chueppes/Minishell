#include "../../includes/minishell.h"

void    do_env(t_data *envp, int type)
{
    int i;

    i = -1;
    if (type == 1)
        while (envp->minishell_envp[++i])
            printf("%s\n", envp->minishell_envp[i]);
    else
        while (envp->minishell_envp[++i])
            printf("declare -x %s\n", envp->minishell_envp[i]);
}
