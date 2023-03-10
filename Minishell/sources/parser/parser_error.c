#include "../.././includes/minishell.h"

static int is_redirect2(int token)
{
	if (token == APPEND_OUTPUT || token == REDIRECT_OUTPUT\
	|| token == REDIRECT_INPUT || token == HEREDOC)
		return (1);
	else
		return (0);
}


int	parser_error(t_data *minishell)
{
	t_commands *aux;

	aux = minishell->commands;
	while (aux != NULL)
	{
		if (aux->cmd[0] == '|' && aux->cmd[1] == '|')
		{
			handle_errors(PIPENDE_ERR, 2, NULL);
			return (-1);
		}
		if (aux->token == PIPE && (aux->next == NULL ||\
		 aux->next->token == PIPE))
		{
			handle_errors(PIPENDE_ERR, 2, NULL);
			return (-1);
		}
		if (is_redirect2(aux->token) && (aux->next == NULL ||\
		is_redirect2(aux->next->token) || aux->next->token == PIPE))
		{
			handle_errors(OPENFILE_ERR, 2, NULL);
			return (-1);
		}
		aux = aux->next;
	}
	return (0);
}