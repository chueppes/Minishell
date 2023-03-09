#include "../includes/minishell.h"

int global;

void	print_start(void)
{
	printf("\033[0;31m%s\n", LINE_1);
	printf("%s\n", LINE_2);
	printf("%s\n", LINE_3);
	printf("%s\n", LINE_4);
	printf("%s\n", LINE_5);
	printf("%s\n", LINE_6);
	printf("%s\n", LINE_7);
	printf("%s\n", LINE_8);
	printf("%s\n", LINE_9);
	printf("%s\n", LINE_10);
	printf("%s\n", LINE_11);
	printf("%s\n", LINE_12);
	printf("%s\n", LINE_13);
	printf("%s\n", LINE_14);
	printf("%s\n", LINE_15);
	printf("%s\n", LINE_16);
	printf("%s\n", LINE_17);
	printf("%s\n", LINE_18);
	printf("%s\n", LINE_20);
	printf("%s\n", LINE_21);
	printf("%s\n", LINE_22);
	printf("%s\n", LINE_23);
	printf("%s\n", LINE_24);
	printf("%s\n\033[0m", LINE_25);
}

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
    print_start();
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
