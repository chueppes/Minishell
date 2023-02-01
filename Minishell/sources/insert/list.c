#include "../.././includes/minishell.h"

void	lstadd_back_command(t_commands **lst, t_commands *new_lst)
{
	t_commands	*list;

	if (!new_lst)
		return ;
	if (!*lst)
	{
		*lst = new_lst;
		return ;
	}
	list = *lst;
    while (list->next != NULL)
    {
        list = list->next;
    }
    list->next = new_lst;
    return ;
}

t_commands	*lstnew_command(char *content)
{
	t_commands	*comm;
    int i;

    i = 0;
	comm = malloc(sizeof(t_commands));
	if (!comm)
		return (NULL);
	while (content[i++])
		comm->cmd[i] = content[i];
	comm->cmd[i] = '\0';
	comm->next = NULL;
	return (comm);
}

void	free_list(t_commands **list)
{
	t_commands	*tmp;

	if (*list == NULL)
    {
		return ;
    }
    tmp = (*list)->next;
    free((*list)->cmd); // limpar array
	free(*list); // limpar lista
	*list = NULL;
	free_list(&tmp);
}