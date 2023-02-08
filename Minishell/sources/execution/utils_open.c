#include "../.././includes/minishell.h"

t_commands *open_input(t_commands **comm)
{
	int infile;

	if ((*comm)->next != NULL)
		*comm = (*comm)->next;
	else
		return(NULL); // fazer função de erro
	infile = open((*comm)->cmd, O_RDONLY);

}

t_commands *open_output(t_commands **comm)
{
	int infile;

	if ((*comm)->next != NULL)
		*comm = (*comm)->next;
	else
		return(NULL); // fazer função de erro
	infile = open((*comm)->cmd, O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

t_commands *open_append(t_commands **comm)
{
	int infile;

	if ((*comm)->next != NULL)
		*comm = (*comm)->next;
	else
		return(NULL); // fazer função de erro
	infile = open((*comm)->cmd, O_WRONLY | O_CREAT | O_APPEND, 0777);
}