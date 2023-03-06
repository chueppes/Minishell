#include "../.././includes/minishell.h"

char	*my_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = -1;
	i = -1;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++j] != '\0')
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	free(s1);
	return (str);
}

int search_redirect(t_commands **comm, t_exec **exec_list)
{
	t_commands	*temp;
	int			i;

	i = 1;
	temp = *comm;
	while (temp && temp->next)
	{
		if(temp->token == HEREDOC)
			open_heredoc(comm, exec_list, i, temp->next->cmd);
		if(temp->token == REDIRECT_INPUT)
			open_input(comm, exec_list, i, temp->next->cmd);
		if(temp->token == REDIRECT_OUTPUT)
			open_output(comm, exec_list, i, temp->next->cmd);
		else if(temp->token == APPEND_OUTPUT)
			open_append(comm, exec_list, i, temp->next->cmd);
		temp = temp->next;
		i++;
	}
	return (1);
}