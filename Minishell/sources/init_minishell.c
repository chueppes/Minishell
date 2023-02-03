#include "../includes/minishell.h"

char **copy_envp(char **envp)
{
    char    **cpy_envp;
    int     amount_strs;
    int     i;

    i = 0;
    amount_strs = count_strs(envp);
    cpy_envp = (char **)malloc(sizeof(char *) * amount_strs);
    while (i < amount_strs - 1)
    {
        cpy_envp[i] = ft_strdup(envp[i]);
        i++;
    }
    cpy_envp[i] = NULL;
    return (cpy_envp);
}

int init_vars(t_data *minishell, char **envp)
{
    char buff[4097];
    char *home;

    home = getenv("HOME"); //recupera uma variavel env
    getcwd(buff, 4096); // pega o caminho atual
    if(ft_memcmp(buff, home, ft_strlen(home)))
        minishell->cwd_path = ft_strdup(buff);
    else
        minishell->cwd_path = ft_strjoin("~", buff + ft_strlen(home));
    minishell->readline = NULL;
    minishell->cmd_split = NULL;
    minishell->commands = NULL;
    minishell->cmd_count = 0;
    minishell->minishell_envp = copy_envp(envp); // inicialização da nossa envp
    return(0);
}

int init_readline(t_data *minishell)
{
    while (1)
    {
        int i;
        minishell->readline = readline("minishell~> ");
        add_history(minishell->readline);
        minishell->expanded_str = separate_by_spaces(minishell->readline);
        minishell->cmd_split = ft_split(minishell->expanded_str, '|');
        minishell->cmd_count = count_strs(minishell->cmd_split);
        i = -1;
        while (minishell->cmd_split[++i])
            lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
        split_list(&minishell->commands);
        minishell->commands->cmd_path = find_path(minishell->commands->exec_cmd[0], minishell->minishell_envp);
        //printf("%s\n", minishell->commands->cmd_path);
/*        while (minishell->commands)
        {
            i = -1;
            printf("%s\n", minishell->commands->cmd);
            while (minishell->commands->exec_cmd[++i])
                printf("%s\n", minishell->commands->exec_cmd[i]);
            minishell->commands = minishell->commands->next;
        }*/
        free_all(minishell);
    }
    return (0);
}