#include ".././includes/minishell.h"

void free_all(t_data *minishell)
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
	free_list(&minishell->commands);
    return ;
}

void	free_list(t_commands **list)
{
	t_commands	*tmp;
    int i;

    i = -1;
	if (*list == NULL)
		return ;
	tmp = (*list)->next;
    free((*list)->cmd);
    (*list)->cmd = NULL;
    free((*list)->cmd_path);
    (*list)->cmd_path = NULL;
    while ((*list)->exec_cmd[++i])
    {
        free((*list)->exec_cmd[i]);
        (*list)->exec_cmd[i] = NULL;
    }
    free((*list)->exec_cmd);
    (*list)->exec_cmd = NULL;
	free(*list);
	*list = NULL;
	free_list(&tmp);
}