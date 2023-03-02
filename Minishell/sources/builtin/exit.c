#include "../../includes/minishell.h"

static void free_for_exit(t_data *minishell)
{
	int i;

	i = -1;
	while (minishell->minishell_envp[++i])
	{
		free(minishell->minishell_envp[i]);
		minishell->minishell_envp[i] = NULL;
	}
	free(minishell->minishell_envp);
	minishell->minishell_envp = NULL;
	free(minishell->old_pwd);
	minishell->old_pwd = NULL;

}

void do_exit(t_data *minishell)
{
	free_for_exit(minishell);
	free_all(minishell);
	exit(0);
}