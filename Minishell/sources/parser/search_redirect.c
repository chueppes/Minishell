#include "../.././includes/minishell.h"

int search_redirect(t_commands *comm)
{
	while (comm->token != PIPE && comm != NULL)
	{
		if(comm->token == REDIRECT_INPUT)
		{
			input_open();
		}
		else if(comm->token == REDIRECT_OUTPUT)
		{
			output_open();
		}
		else if(comm->token == APPEND_OUTPUT)
		{
			append_open();
		}
	}
}