#include "../../includes/minishell.h"

char **unset_env(char **envp, int unset_i)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = -1;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
    while (++i < amount_strs && i != unset_i)
        cpy_envp[i] = ft_strdup(envp[i]);
    cpy_envp[i] = NULL;
    return (cpy_envp);
}

void    do_unset(char **env, char *unset, t_data *mini)
{
    int i;
    int len_unset;

    i = -1;
    len_unset = ft_strlen(unset);
    while(env[++i])
    {
        if(ft_strncmp(unset, env[i], len_unset) == 0)
            mini->minishell_envp = unset_env(env, i);
    }
}
