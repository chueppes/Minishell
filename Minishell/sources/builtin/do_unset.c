#include "../../includes/minishell.h"

int  count_strs(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != NULL)
     i++;
    return (i);
}

char **unset_env(char **envp, int unset_i)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = -1;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
    while (++i < (amount_strs - 1) && i != unset_i)
        cpy_envp[i] = strdup(envp[i]);
    cpy_envp[i] = NULL;
    return (cpy_envp);
}

char    **do_unset(char **env, char *unset)
{
    int i;
    int len_unset;
    char **new_env;

    i = -1;
    len_unset = strlen(unset);
    while(env[++i])
    {
        if(strncmp(unset, env[i], len_unset) == 0)
        {
            new_env = unset_env(env, i);
            env = new_env;
            free(new_env);
            return(env);
        }
    }
    return (NULL);
}
