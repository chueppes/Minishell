#include "../.././includes/minishell.h"

void exec_child(t_data *mini, int *prevpipe, t_exec *exec_list, int pipefd[2])
{
	close (pipefd[0]);
	dup2 (pipefd[1], STDOUT_FILENO);
	close (pipefd[1]);
	dup_outfile(exec_list);
	dup2 (*prevpipe, STDIN_FILENO);
	close (*prevpipe);
	dup_infile(exec_list);
	execve(find_path(exec_list->exec_cmd[0], mini->minishell_envp), exec_list->exec_cmd, mini->minishell_envp);
}

void exec_child_last(t_data *mini, int prevpipe, t_exec *exec_list)
{
	dup2 (prevpipe, STDIN_FILENO);
	close (prevpipe);
	dup_outfile(exec_list);
	dup_infile(exec_list);
	execve(find_path(exec_list->exec_cmd[0], mini->minishell_envp), exec_list->exec_cmd, mini->minishell_envp);
}

void main_process(int *prevpipe, int pipefd[2], t_exec *exec_list)
{
	close (pipefd[1]);
	close (*prevpipe);
	close_infile(exec_list);
	close_outfile(exec_list);
	*prevpipe = pipefd[0];
}

void main_process_last(int prevpipe, t_exec *exec_list)
{
	close (prevpipe);
	close_infile(exec_list);
	close_outfile(exec_list);
	while (wait (NULL) != -1)
		;
}