#include "../includes/minishell.h"

void     exec_env(t_data *data)
{
    int i=-1;
    while(data->minishell_envp[++i])
        printf("%s\n", data->minishell_envp[i]);
}

int is_builtin(t_data *data)
{
    if(!ft_strncmp(data->cmd_split[0], "env", 4))
        exec_env(data);
    return(0);
}