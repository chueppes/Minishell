#include "../.././includes/minishell.h"

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
	free_list_comm(&minishell->commands);
	if (minishell->exec_list != NULL)
		free_list_exec(&minishell->exec_list);
    return ;
}

void	free_list_comm(t_commands **list)
{
	t_commands	*tmp;
	
	if (*list == NULL)
		return ;
	tmp = (*list)->next;
    free((*list)->cmd);
    (*list)->cmd = NULL;
	free(*list);
	*list = NULL;
	free_list_comm(&tmp);
}

void	free_list_exec(t_exec **list)
{
	t_exec	*tmp;
	int i;
	
	i = -1;
	if (*list == NULL)
		return ;
	tmp = (*list)->next;
    free((*list)->aux);
    (*list)->aux = NULL;
	while ((*list)->exec_cmd[++i])
	{
		(*list)->exec_cmd[i] = NULL;
		free((*list)->exec_cmd[i]);
	}
	(*list)->exec_cmd = NULL;
	free(*list);
	*list = NULL;
	free_list_exec(&tmp);
}