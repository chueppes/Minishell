#include "../.././includes/minishell.h"

void prepare_for_execution(t_exec **exec_list)
{
	t_exec	*temp;

	temp = *exec_list;
	while (temp)
	{
		temp->exec_cmd = split_quotes(temp->aux, ' ');
		temp = temp->next;
	}
}

