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

int open_output(t_commands **comm, t_exec **exec_list, int i)
{
//	t_commands	*temp_comm;
//	t_data		*temp_exec;
	int			find_list;
	(void)exec_list;

//	temp_comm = *comm;
//	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	while ()// parei aqui
	printf("i = %d, find_list = %d\n", i, find_list);
	return (0);
}

/*int *open_append(t_commands **comm, int i)
{
	int infile;

	if ((*comm)->next != NULL)
		*comm = (*comm)->next;
	else
		return(NULL); // fazer função de erro
	infile = open((*comm)->cmd, O_WRONLY | O_CREAT | O_APPEND, 0777);
}*/