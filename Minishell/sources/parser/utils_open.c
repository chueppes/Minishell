#include "../.././includes/minishell.h"

int find_position_open(t_commands *comm, int i)
{
	int count_pipe;

	count_pipe = 0;
	while (i--)
	{
		if (comm->token == PIPE)
			count_pipe++;
		comm = comm->next;
	}
	return (count_pipe);
}

/*int *open_input(t_data *mini, int i)
{
	int			open_exec;
	t_exec		temp_exec;

	open_exec = 1;
	open_exec = find_position_open(t_data *mini)
	while (open_exec--)
	{
		mini->exec_
	}

}*/

int open_output(t_commands **comm, t_exec **exec_list, int i, char *file)
{
	t_exec		*temp_exec;
	int			find_list;

	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
		temp_exec->outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	else
		open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (0);
}

int open_append(t_commands **comm, t_exec **exec_list, int i, char *file)
{
	t_exec	*temp_exec;
	int		find_list;

	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
		temp_exec->outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	else
		open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (0);
}