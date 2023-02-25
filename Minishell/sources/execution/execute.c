#include "../.././includes/minishell.h"

void	executioner(t_data *minishell)
{
	int fd;

	fd = fork();
	if (fd == 0)
	{
		execve(find_path(minishell->exec_list->exec_cmd[0], minishell->minishell_envp),
		 minishell->exec_list->exec_cmd, minishell->minishell_envp);
	}
	else if (fd != 0)
		wait(NULL);
}