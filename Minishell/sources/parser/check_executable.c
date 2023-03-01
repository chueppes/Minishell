#include "../.././includes/minishell.h"

int check_executable(t_commands *check_exec)
{
	while(check_exec)
	{
		if (check_exec->token == NORMAL_ARG)
			return(1);
		check_exec = check_exec->next;
	}
	return (0);
}