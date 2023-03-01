#include "../../includes/minishell.h"

char **modify_env(char **envp, char *str, int j)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = -1;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs + 1);
    while (++i < (amount_strs - 1) && ft_strncmp(envp[i], str, j) != 0)
        cpy_envp[i] = ft_strdup(envp[i]);
    cpy_envp[i] = ft_strdup(str);
    while (++i < (amount_strs - 1) )
        cpy_envp[i] = ft_strdup(envp[i]);
    cpy_envp[i] = NULL;
    return (cpy_envp);
}

char **add_env(char **envp, char *str)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = -1;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs + 1);
    while (++i < (amount_strs - 1))
        cpy_envp[i] = ft_strdup(envp[i]);
    cpy_envp[i] = ft_strdup(str);
    cpy_envp[i + 1] = NULL;
    return (cpy_envp);
}

void    do_export(char **envp, char *str, t_data *mini)
{
    int i;
    int j;
    int exec;

    i = 0;
    exec = 0;
    j = 0;
    while (str[i] != '=' && str[i])
        i++;
    if (str[i] == '\0')
        str = ft_strjoin(str, "="); //TESTAR
    while (envp[j])
    {
        if(ft_strncmp(envp[j], str, i) == 0)
        {
            exec = 1;
            mini->minishell_envp = modify_env(envp, str, i);
        }
        j++;
    }
    if (exec == 0)
        mini->minishell_envp = add_env(envp, str);
}
