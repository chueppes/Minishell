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

int execution(t_data *minishell)
{
	if (count_commands(minishell->exec_list) == 1)
	{
		if (single_command(minishell) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (execute_pipes(minishell) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int single_command(t_data *minishell)
{
	pid_t	fpid;
	pid_t	heredocpid;
	char	*path;
	int		status;

	status = 0;
	if (is_builtin(minishell->exec_list->exec_cmd[0]))
	{
		if (minishell->exec_list->heredoc_str != NULL)
			free(minishell->exec_list->heredoc_str);
		dup_infile(minishell->exec_list);
		dup_outfile(minishell->exec_list);
		exec_builtin(minishell->exec_list, minishell);
	}
	else
	{
		path = find_path(minishell->exec_list->exec_cmd[0], minishell->minishell_envp);
		fpid = fork();
		if (fpid == -1)
		{
			handle_errors(FORK_ERR, 1, NULL);
			free_all(minishell);
			exit(1);
			return (FAILURE);
		}
		if (fpid == 0)
		{
			child_signals();
			if (minishell->exec_list->has_doc == 1)
			{
				heredocpid = heredoc_exec_single(minishell);
				if (heredocpid == FAILURE)
					return (FAILURE);
				if (heredocpid != 0)
				{
					dup_infile(minishell->exec_list);
					dup_outfile(minishell->exec_list);
					if (path == NULL)
						exit(127);
					execve(path, minishell->exec_list->exec_cmd, minishell->minishell_envp);
				}
			}
			else 
			{
				dup_infile(minishell->exec_list);
				dup_outfile(minishell->exec_list);
				if (path == NULL)
					exit(127);
				execve(path, minishell->exec_list->exec_cmd, minishell->minishell_envp);
			}
		}
		if (fpid != 0)
		{
			if (access(path, F_OK) == -1)
			{
				handle_errors(CMDNOTFOUND_ERR, 127, minishell->exec_list->exec_cmd[0]);
				status = -1;
			}
			else if (access(path, X_OK) == -1)
			{
				handle_errors(NPERM_ERR, 126, NULL);
				status = -1;
			}
			if (path != NULL)
				free(path);
			close_infile(minishell->exec_list);
			close_outfile(minishell->exec_list);
			wait(NULL);
		}
	}
	return (status);
}
