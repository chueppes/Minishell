#include "../.././includes/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

void	exec_builtin(t_exec *cmd, t_data *minishell)
{
	int	i;

	i = 0;
	if (ft_strcmp(cmd->exec_cmd[0], "echo") == 0)
		do_echo(cmd->exec_cmd);
	else if (ft_strcmp(cmd->exec_cmd[0], "cd") == 0 && cmd->exec_cmd[1])
		do_cd(cmd->exec_cmd[1], minishell->minishell_envp, minishell, 0);
	else if (ft_strcmp(cmd->exec_cmd[0], "cd") == 0 && !cmd->exec_cmd[1])
		do_cd(cmd->exec_cmd[1], minishell->minishell_envp, minishell, 1);
	else if (ft_strcmp(cmd->exec_cmd[0], "pwd") == 0)
		do_pwd();
	else if (ft_strcmp(cmd->exec_cmd[0], "export") == 0)
	{
		if (!cmd->exec_cmd[1])
			do_export(minishell->minishell_envp, cmd->exec_cmd[1], minishell);
		while (cmd->exec_cmd[++i])
			do_export(minishell->minishell_envp, cmd->exec_cmd[i], minishell);
	}
	else if (ft_strcmp(cmd->exec_cmd[0], "unset") == 0)
		while (cmd->exec_cmd[++i])
			do_unset(minishell->minishell_envp, cmd->exec_cmd[i], minishell);
	else if (ft_strcmp(cmd->exec_cmd[0], "env") == 0)
		do_env(minishell, 1);
//	else if (ft_strcmp(cmd->exec_cmd[0], "exit") == 0)
		//return (42);
}

int	ft_last_prog(t_data *mini, int prevpipe, t_exec *exec_list)
{
	pid_t	cpid;

	if (exec_list->has_doc == 1)
		pipe(exec_list->pipe_heredoc);
	cpid = fork();
	if (cpid == -1)
	{
		handle_errors(FORK_ERR, 1, NULL);
		free_all(mini);
		exit(1);
		return (FAILURE);
	}
	if (cpid  != 0)
	{
		if (main_process_last(prevpipe, exec_list, mini) == -1)
			return (FAILURE);
	}
	if (cpid == 0)
	{
		child_signals();
		exec_child_last(mini, prevpipe, exec_list);
	}
	return (SUCCESS);
}

int	ft_pipe(t_data *mini, int *prevpipe, t_exec *exec_list)
{
	int		pipefd[2];
	pid_t	cpid;

	if (pipe(pipefd) == -1)
	{
		handle_errors(PIPERR_ERR, 1, NULL);
		return (FAILURE);
	}
	if (exec_list->has_doc == 1)
		pipe(exec_list->pipe_heredoc);
	cpid = fork();
	if (cpid == -1)
		return (exec_fork_error(mini));
	if (cpid != 0)
	{
		if (main_process(prevpipe, pipefd, exec_list, mini) == FAILURE)
			return (FAILURE);
	}
	if (cpid == 0)
	{
		child_signals();
		exec_child(mini, prevpipe, exec_list, pipefd);
	}
	return (SUCCESS);
}

int	execute_pipes(t_data *minishell)
{
	int	prevpipe;
	int status;

	status = 0;
	prevpipe = dup(0);
	while (minishell->exec_list)
	{
		if (minishell->exec_list->next != NULL)
		{
			if (ft_pipe(minishell, &prevpipe, minishell->exec_list) == FAILURE)
				status = -1;
		}
		else
		{
			if (ft_last_prog(minishell, prevpipe, minishell->exec_list) == FAILURE)
				status = -1;	
		}
		minishell->exec_list = minishell->exec_list->next;
		if (status == -1)
			break ;
	}
	return (status);
}
