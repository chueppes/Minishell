#include "../.././includes/minishell.h"

/*int do_exec(t_data *minishell)
{
	t_commands *aux;
	int pipes_count;

	pipes_count = count_pipes(minishell->commands);
	aux = minishell->commands;
	while (aux != NULL)
	{
		is_redirect(&aux);
		is_builtin(&aux);
	}
}

t_commands *is_redirect(t_commands **comm)
{
	t_commands *aux;

	aux = *comm;
	if (aux->token == REDIRECT_INPUT)
		return (do_redirect_input(comm));
	else if (aux->token == REDIRECT_OUTPUT)
		return (do_redirect_output(comm));
	else if (aux->token == APPEND_OUTPUT)
		return (do_append_output(comm));
	else if (aux->token == HEREDOC)
		return (do_redirect_output(comm));
	else
		return (*comm);
}*/

/*t_commands *is_builtin(t_data *minishell)
{
	if (ft_strcmp(temp->cmd, "echo")
		do_echo();
	

}*/