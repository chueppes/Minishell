#include "../.././includes/minishell.h"

void free_parser(t_data *minishell)
{
	int i;

	i = -1;
	free(minishell->readline);
	minishell->readline = NULL;
	free(minishell->expanded_str);
	minishell->expanded_str = NULL;
	while (minishell->cmd_split[++i])
	{
		free(minishell->cmd_split[i]);
		minishell->cmd_split[i] = NULL;
	}
	free(minishell->cmd_split);
	minishell->cmd_split = NULL;
	free_list_comm(&minishell->commands);
}