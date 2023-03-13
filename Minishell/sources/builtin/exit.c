#include "../../includes/minishell.h"

void do_exit(t_data *minishell)
{
    int i;

    i = -1;
    free_all(minishell);
    while (minishell->minishell_envp[++i])
        free(minishell->minishell_envp[i]);
    free(minishell->minishell_envp);
    free(minishell->old_pwd);
    printf("exit\n");
	exit(0);
}