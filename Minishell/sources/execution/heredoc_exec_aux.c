#include "../.././includes/minishell.h"

pid_t heredoc_exec_single(t_data *minishell)
{
	pid_t heredocpid;

	pipe(minishell->exec_list->pipe_heredoc);
	heredocpid = fork();
	if (heredocpid == 0)
	{
		close(minishell->exec_list->pipe_heredoc[0]);
		ft_putstr_fd(minishell->exec_list->heredoc_str, minishell->exec_list->pipe_heredoc[1]);
		free(minishell->exec_list->heredoc_str);
		close(minishell->exec_list->pipe_heredoc[1]);
		exit(0);
	}
	if (heredocpid != 0)
	{
		close(minishell->exec_list->pipe_heredoc[1]);
		dup2(minishell->exec_list->pipe_heredoc[0], STDIN_FILENO);
		close(minishell->exec_list->pipe_heredoc[0]);
	}
	return (heredocpid);
}

pid_t heredoc_exec_pipes(t_exec	*exec_list)
{
	pid_t heredocpid;

	pipe(exec_list->pipe_heredoc);
	heredocpid = fork();
	if (heredocpid == 0)
	{
		close(exec_list->pipe_heredoc[0]);
		ft_putstr_fd(exec_list->heredoc_str, exec_list->pipe_heredoc[1]);
		free(exec_list->heredoc_str);
		close(exec_list->pipe_heredoc[1]);
		exit(0);
	}
	if (heredocpid != 0)
	{
		close(exec_list->pipe_heredoc[1]);
		dup2(exec_list->pipe_heredoc[0], STDIN_FILENO);
		close(exec_list->pipe_heredoc[0]);
	}
	return (heredocpid);
}