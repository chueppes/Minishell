#include "../includes/minishell.h"

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
	while (list->next)
		list = list->next;
	list->next = new_lst;
	return ;
}

t_commands	*lstnew_command(char *content)
{
	t_commands	*comm;

	comm = malloc(sizeof(t_commands));
	if (!comm)
		return (NULL);
	comm->cmd = ft_strdup(content);
	comm->next = NULL;
	return (comm);
}

void	split_list(t_commands **command)
{
	int i;
	t_commands *temp;
	t_commands *temp2;
	i = -1;
	temp = *command;
	temp2 = *command;

	while(temp)
	{
		temp->exec_cmd = split_quotes(temp->cmd, ' ');
		temp = temp->next;
	}
	return ;
}