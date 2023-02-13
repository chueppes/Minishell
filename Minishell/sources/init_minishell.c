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
	minishell->exec_list = NULL;
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
        minishell->cmd_split = split_quotes(minishell->expanded_str, ' ');
        create_list(minishell);
        executioner(minishell);
//        print_commands(minishell->commands);

//        free_all(minishell);
    }
    return (0);
}