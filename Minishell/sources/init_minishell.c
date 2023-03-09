#include "../includes/minishell.h"

int global;

int init_vars(t_data *minishell, char **envp)
{
    minishell->readline = NULL;
    minishell->cmd_split = NULL;
    minishell->commands = NULL;
	minishell->exec_list = NULL;
    minishell->online = 1;
    minishell->minishell_envp = copy_envp(envp); // inicialização da nossa envp
	minishell->old_pwd = getcwd(NULL, 0);
    return(0);
}

int init_readline(t_data *minishell)
{
    clear_up();
    while (1)
    {
        signals();
        minishell->readline = readline("minishell~> ");
        if(minishell->readline == NULL)
            break ;
        if(!treat_input(minishell))
        {
            parser(minishell);
            execution(minishell);
		    free_all(minishell);
        }
        free(minishell->readline);
    }
    return (0);
}
