#include "../includes/minishell.h"

int global;

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
    minishell->online = 1;
    minishell->minishell_envp = copy_envp(envp); // inicialização da nossa envp
    return(0);
}

int init_readline(t_data *minishell)
{
    clear_up();
    while (1)
    {
    //    sigint_parser();
        minishell->readline = readline("minishell~> ");
        if(minishell->readline == NULL)
            break ;
        treat_input(minishell);
        parser(minishell);
        execution(minishell);
		free_all(minishell);
    }
    return (0);
}