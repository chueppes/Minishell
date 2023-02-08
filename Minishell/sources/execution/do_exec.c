#include "../.././includes/minishell.h"

int do_exec(t_data *minishell)
{
	int pipes_count;
	int has_redirect;
	int infile;
	int outfile;

	pipes_count = count_pipes(minishell->commands);
	is_redirect(&minishell->commands);
}

int is_redirect(t_commands **comm)
{
	t_commands *aux;

	aux = *comm;
	while (aux != NULL || aux->token != PIPE)
	{
		if (aux->token == REDIRECT_INPUT)
			return (open_input(aux));
		else if (aux->token == REDIRECT_OUTPUT)
			return (open_output(aux));
		else if (aux->token == APPEND_OUTPUT)
			return (open_append(aux));
		
	}
}
/*t_commands *is_builtin(t_data *minishell)
{
	if (ft_strcmp(temp->cmd, "echo")
		do_echo();
	

}*/