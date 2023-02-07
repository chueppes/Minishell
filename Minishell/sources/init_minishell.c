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
        minishell->readline = readline("minishell~> ");
        add_history(minishell->readline);
        minishell->expanded_str = separate_by_spaces(minishell->readline);
        create_list(minishell);
        while (minishell->commands)
        {
            printf("%d\n", minishell->commands->token);
            printf("%s\n", minishell->commands->cmd);
            minishell->commands = minishell->commands->next;
        }
/*        split_list(&minishell->commands);
        j = 0;
        check_input(minishell);
            minishell->commands->cmd_path = find_path(minishell->commands->exec_cmd[j], minishell->minishell_envp);*/
        free_all(minishell);
    }
    return (0);
}