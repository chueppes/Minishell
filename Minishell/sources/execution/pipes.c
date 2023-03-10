#include "../.././includes/minishell.h"


int is_builtin(char *cmd)
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

void exec_builtin(t_exec *cmd, t_data *minishell)
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
		while (cmd->exec_cmd[++i])
	    	do_export(minishell->minishell_envp, cmd->exec_cmd[i], minishell);
  else if (ft_strcmp(cmd->exec_cmd[0], "unset") == 0)
    	while (cmd->exec_cmd[++i])
	    	do_unset(minishell->minishell_envp, cmd->exec_cmd[i], minishell);
	else if (ft_strcmp(cmd->exec_cmd[0], "env") == 0)
		do_env(minishell, 1);
//    else if (ft_strcmp(cmd->exec_cmd[0], "exit") == 0)
//		return (42);
}

void	ft_last_prog(t_data *mini, int prevpipe, t_exec *exec_list)
{
	pid_t	cpid;

	cpid = fork ();
	if (cpid == 0)
  {
    child_signals();
		exec_child_last(mini, prevpipe, exec_list);
  }
  else
  	main_process_last(prevpipe, exec_list);
}

void	ft_pipe(t_data *mini, int *prevpipe, t_exec *exec_list)
{
	int		pipefd[2];
	pid_t	cpid;

	pipe (pipefd);
	cpid = fork ();
	if (cpid == 0)
  {
    child_signals();
		exec_child(mini, prevpipe, exec_list, pipefd);
  }
  else
		main_process(prevpipe, pipefd, exec_list);
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
