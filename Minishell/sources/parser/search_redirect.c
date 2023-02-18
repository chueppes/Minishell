#include "../.././includes/minishell.h"

int search_redirect(t_commands **comm, t_exec **exec_list)
{
	t_commands	*temp;
	int			i;

	i = 1;
	temp = *comm;
	while (temp && temp->next)
	{
//		if(temp->token == REDIRECT_INPUT)
//			input_open(comm, exec_list, i);
		if(temp->token == REDIRECT_OUTPUT)
			open_output(comm, exec_list, i, temp->next->cmd);
//		else if(temp->token == APPEND_OUTPUT)
//			append_open(comm, exec_list, i);
		temp = temp->next;
		i++;
	}
	return (1);
}