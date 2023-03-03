#include "../.././includes/minishell.h"

int	count_commands(t_exec *exec_list)
{
	int i;

	i = 0;
	while (exec_list)
	{
		exec_list = exec_list->next;
		i++;
	}
	return (i);
}

void execution(t_data *minishell)
{
	if (count_commands(minishell->exec_list) == 1)
		single_command(minishell);
	else
		execute_pipes(minishell);
}

void single_command(t_data *minishell)
{
	pid_t	fpid;

	if (is_builtin(minishell->exec_list->exec_cmd[0]))
		exec_builtin(minishell->exec_list, minishell);
	else
	{
		fpid = fork();
		if (fpid == 0)
		{
			dup_infile(minishell->exec_list);
			dup_outfile(minishell->exec_list);
			execve(find_path(minishell->exec_list->exec_cmd[0], minishell->minishell_envp), minishell->exec_list->exec_cmd, minishell->minishell_envp);
		}
		else
		{
			close_infile(minishell->exec_list);
			close_outfile(minishell->exec_list);
			wait(NULL);
		}
	}
}