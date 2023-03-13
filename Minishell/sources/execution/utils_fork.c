#include "../.././includes/minishell.h"

void	exec_child(t_data *mini, int *prevpipe, t_exec *exec_list, int pipefd[2])
{
	char *path;

	close (pipefd[0]);
	dup2 (pipefd[1], STDOUT_FILENO);
	close (pipefd[1]);
	dup_outfile(exec_list);
	dup2 (*prevpipe, STDIN_FILENO);
	close (*prevpipe);
	dup_infile(exec_list);
	if (exec_list->has_doc == 1)
		has_doc_child(exec_list);
	if (is_builtin(exec_list->exec_cmd[0]))
 	{
   		exec_builtin(exec_list, mini);
    	exit(0) ;
 	}
	else
	{
		path = find_path(exec_list->exec_cmd[0], mini->minishell_envp);
		if (path == NULL)
			exit(127);
		execve(path, exec_list->exec_cmd, mini->minishell_envp);
	}
}

void exec_child_last(t_data *mini, int prevpipe, t_exec *exec_list)
{
	char *path;

	dup2 (prevpipe, STDIN_FILENO);
	close (prevpipe);
	dup_outfile(exec_list);
	dup_infile(exec_list);
	if (exec_list->has_doc == 1)
		has_doc_child(exec_list);
	if (is_builtin(exec_list->exec_cmd[0]))
	{
		exec_builtin(exec_list, mini);
		exit(0);
	}
	else
	{
		path = find_path(exec_list->exec_cmd[0], mini->minishell_envp);
		if (path == NULL)
			exit (127);
		execve(path, exec_list->exec_cmd, mini->minishell_envp);
	}
}

int main_process(int *prevpipe, int pipefd[2], t_exec *exec_list, t_data *mini)
{
	char *path;
	int status;

	status = 0;
	if (exec_list->has_doc == 1)
		has_doc_main(exec_list);
	path = find_path(exec_list->exec_cmd[0], mini->minishell_envp);
	if (access(path, X_OK) == -1)
	{
		handle_errors(NPERM_ERR, 126, NULL);
		status = -1;
	}
	else if (access(path, F_OK) == -1)
	{
		handle_errors(CMDNOTFOUND_ERR, 127, exec_list->exec_cmd[0]);
		status = -1;
	}
	if (path != NULL)
		free(path);
	close (pipefd[1]);
	close (*prevpipe);
	close_infile(exec_list);
	close_outfile(exec_list);
	*prevpipe = pipefd[0];
	return (status);
}

int main_process_last(int prevpipe, t_exec *exec_list, t_data *mini)
{
	char *path;
	int status;

	status = 0;
	if (exec_list->has_doc == 1)
		has_doc_main(exec_list);
	path = find_path(exec_list->exec_cmd[0], mini->minishell_envp);
	if (access(path, X_OK) == -1)
	{
		status = -1;
		handle_errors(NPERM_ERR, 126, NULL);
	}
	else if (access(path, F_OK) == -1)
	{
		status = -1;
		handle_errors(CMDNOTFOUND_ERR, 127, exec_list->exec_cmd[0]);
	}
	if (path != NULL)
		free(path);
	close (prevpipe);
	close_infile(exec_list);
	close_outfile(exec_list);
	while (wait (NULL) != -1)
		;
	return (status);
}
