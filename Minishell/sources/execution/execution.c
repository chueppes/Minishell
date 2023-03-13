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
	int status;

	status = SUCCESS;
	if (count_commands(minishell->exec_list) == 1)
	{
		if (single_command(minishell) == FAILURE)
			status = FAILURE;
	}
	else
	{
		if (execute_pipes(minishell) == FAILURE)
			status = FAILURE;
	}
	return (status);
}

static int main_execution(t_data *minishell, char *path)
{
	int status;

	status = 0;
	if (minishell->exec_list->has_doc == 1)
		has_doc_main_single(minishell);
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
	return (status);
}

static void child_execution(t_data *minishell, char *path)
{
	child_signals();
	if (minishell->exec_list->has_doc == 1)
	{
		close(minishell->exec_list->pipe_heredoc[1]);
		dup2(minishell->exec_list->pipe_heredoc[0], STDIN_FILENO);
		close(minishell->exec_list->pipe_heredoc[0]);
	}
	dup_infile(minishell->exec_list);
	dup_outfile(minishell->exec_list);
	if (path == NULL)
		exit(127);
	execve(path, minishell->exec_list->exec_cmd, minishell->minishell_envp);
}

int single_command(t_data *minishell)
{
	pid_t	fpid;
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
		if (minishell->exec_list->has_doc == 1)
			pipe(minishell->exec_list->pipe_heredoc);
		path = find_path(minishell->exec_list->exec_cmd[0], minishell->minishell_envp);
		fpid = fork();
		if (fpid != 0)
			status = main_execution(minishell, path);
		if (fpid == 0)
			child_execution(minishell, path);
	}
	return (status);
}
