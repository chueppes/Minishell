#include "../.././includes/minishell.h"

int  count_pipes(t_commands *comm)
{
    int i;

    i = 0;
    while (comm != NULL)
	{
		if (comm->cmd[0] == '|' && comm->cmd[1] == '\0')
			i++;
		comm = comm->next;
	}
    return (i);
}

void	ft_last_prog(t_exec *exec_list, int prevpipe, char **envp)
{
	pid_t	cpid;

	cpid = fork ();
	if (cpid == 0)
	{
		dup2 (prevpipe, STDIN_FILENO);
		close (prevpipe);
		if (exec_list->infile != 0)
		{
			dup2 (exec_list->infile, STDIN_FILENO);
			close(exec_list->infile);
		}
		if (exec_list->outfile != 0)
		{
			dup2 (exec_list->outfile, STDOUT_FILENO);
			close(exec_list->outfile);
		}
		execve (find_path(exec_list->exec_cmd[0], envp), exec_list->exec_cmd, envp);
	}
	else
	{
		close (prevpipe);
		while (wait (NULL) != -1)
			;
	}
}

void	ft_pipe(t_exec *exec_list, int *prevpipe, char **envp)
{
	int		pipefd[2];
	pid_t	cpid;

	pipe (pipefd);
	cpid = fork ();
	if (cpid == 0)
	{
		close (pipefd[0]);
		dup2 (pipefd[1], STDOUT_FILENO);
		close (pipefd[1]);
		if (exec_list->outfile != 0)
		{
			dup2 (exec_list->outfile, STDOUT_FILENO);
			close(exec_list->outfile);
		}
		dup2 (*prevpipe, STDIN_FILENO);
		close (*prevpipe);
		if (exec_list->infile != 0)
		{
			dup2 (exec_list->infile, STDIN_FILENO);
			close(exec_list->infile);
		}
		execve (find_path(exec_list->exec_cmd[0], envp), exec_list->exec_cmd, envp);
	}
	else
	{
		close (pipefd[1]);
		close (*prevpipe);
		*prevpipe = pipefd[0];
	}
}

int execute_pipes(t_data *minishell)
{
	int prevpipe;
	prevpipe = dup(0);
	while (minishell->exec_list)
	{
		if (minishell->exec_list->next != NULL)
			ft_pipe(minishell->exec_list, &prevpipe, minishell->minishell_envp);
		else
			ft_last_prog(minishell->exec_list, prevpipe, minishell->minishell_envp);
		minishell->exec_list = minishell->exec_list->next;
	}
	return 0;
}