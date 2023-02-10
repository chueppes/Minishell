#include "../.././includes/minishell.h"

static int is_redirect(t_commands *comm)
{
	if (comm->token == APPEND_OUTPUT && comm->token == REDIRECT_OUTPUT\
	&& comm->token == REDIRECT_INPUT && comm->token == HEREDOC\
	&& comm->token == FILE_NAME && comm->token == DELIMITER)
		return (1);
	else
		return (0);
}

t_exec	*create_exec_list(t_commands *comm)
{
	char *temp;
	t_exec *exec_list;

	exec_list = NULL;
	temp = NULL;
	while (comm)
	{
		if (!is_redirect(comm) && comm->token != PIPE)
			temp = ft_strjoin(temp, comm->cmd);
		if (comm->token == PIPE)
		{
			lstadd_back_exec(&exec_list, lstnew_exec(temp));
			free(temp);
			temp = NULL;
		}
		comm = comm->next;
	}
	return (exec_list);
}