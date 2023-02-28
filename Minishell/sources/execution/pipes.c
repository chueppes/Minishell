#include "../.././includes/minishell.h"

static int is_builtin(char *cmd)
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

static void exec_builtin(t_exec *cmd, t_data *minishell)
{
	if (ft_strcmp(cmd->exec_cmd[0], "echo") == 0)
		do_echo(cmd->exec_cmd);
    else if (ft_strcmp(cmd->exec_cmd[0], "cd") == 0 && cmd->exec_cmd[1])
		do_cd(cmd->exec_cmd[1], minishell->minishell_envp, minishell, 0);
	else if (ft_strcmp(cmd->exec_cmd[0], "cd") == 0 && !cmd->exec_cmd[1])
		do_cd(cmd->exec_cmd[1], minishell->minishell_envp, minishell, 1);
    else if (ft_strcmp(cmd->exec_cmd[0], "pwd") == 0)
		do_pwd();
    else if (ft_strcmp(cmd->exec_cmd[0], "export") == 0)
		do_export(minishell->minishell_envp, cmd->exec_cmd[1], minishell);
    else if (ft_strcmp(cmd->exec_cmd[0], "unset") == 0)
		do_unset(minishell->minishell_envp, cmd->exec_cmd[1], minishell);
    else if (ft_strcmp(cmd->exec_cmd[0], "env") == 0)
		do_env(minishell);
//    else if (ft_strcmp(cmd->exec_cmd[0], "exit") == 0)
//		return (42);
}

void	ft_last_prog(t_data *mini, int prevpipe, t_exec *exec_list)
{
	pid_t	cpid;

	cpid = 0;
	if (!is_builtin(exec_list->exec_cmd[0]))
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
		if (!is_builtin(exec_list->exec_cmd[0]))
			execve(find_path(exec_list->exec_cmd[0], mini->minishell_envp), exec_list->exec_cmd, mini->minishell_envp);
		else
			exec_builtin(exec_list, mini);
	}
	else
	{
		close (prevpipe);
		while (wait (NULL) != -1)
			;
	}
}

void	ft_pipe(t_data *mini, int *prevpipe, t_exec *exec_list)
{
	int		pipefd[2];
	pid_t	cpid;

	cpid = 0;
	pipe (pipefd);
	if (!is_builtin(exec_list->exec_cmd[0]))
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
		if (!is_builtin(exec_list->exec_cmd[0]))
			execve(find_path(exec_list->exec_cmd[0], mini->minishell_envp), exec_list->exec_cmd, mini->minishell_envp);
		else
			exec_builtin(exec_list, mini);
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
			ft_pipe(minishell, &prevpipe, minishell->exec_list);
		else
			ft_last_prog(minishell, prevpipe, minishell->exec_list);
		minishell->exec_list = minishell->exec_list->next;
	}
	return 0;
}