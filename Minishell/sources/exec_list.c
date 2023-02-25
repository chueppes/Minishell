#include ".././includes/minishell.h"

void	lstadd_back_exec(t_exec **lst, t_exec *new_lst)
{
	t_exec	*list;

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

t_exec	*lstnew_exec(char *content)
{
	t_exec	*comm;

	comm = malloc(sizeof(t_exec));
	if (!comm)
		return (NULL);
	comm->aux = ft_strdup(content);
	comm->next = NULL;
	return (comm);
}