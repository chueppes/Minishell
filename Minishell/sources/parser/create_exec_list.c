#include "../.././includes/minishell.h"

static char	*my_strjoin(char *s1, char *s2, int *size)
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
	str[i] = '\0';
	*size = i;
	free(s1);
	return (str);
}

static void free_used(char **array, char *temp)
{
	int i;

	i = -1;
	while(array[++i])
		free(array[i]);
	free(array);
	return ;
}

static int is_redirect(t_commands *comm)
{
	if (comm->token == APPEND_OUTPUT || comm->token == REDIRECT_OUTPUT\
	|| comm->token == REDIRECT_INPUT || comm->token == HEREDOC\
	|| comm->token == FILE_NAME || comm->token == DELIMITER)
		return (1);
	else
		return (0);
}

static void do_list(t_exec **exec_list, char *temp)
{
	int i;
	char **array;

	array = NULL;
	array = split_quotes(temp, '|');
	if (!array && !*array)
		return ;
	i = -1;
	while (array[++i])
		lstadd_back_exec(exec_list, lstnew_exec(array[i]));
	free_used(array, temp);
}

void	create_exec_list(t_exec **exec_list, t_commands *comm)
{
	int size;
	char *temp;
	t_commands *check_exec;

	temp = NULL;
	check_exec = comm;
	while (comm)
	{
		if (!is_redirect(comm))
		{
			if (!temp)
			{
				temp = malloc(1);
				*temp = '\0';
			}
			temp = my_strjoin(temp, comm->cmd, &size);
			if (comm->next != NULL)
			{
				temp[size] = ' ';
				temp[size + 1] = '\0';
			}
		}
		comm = comm->next;
	}
	if (temp != NULL && check_executable(check_exec)) // não é aqui que eu tenho que resolver isso
		do_list(exec_list, temp);
	free(temp);
	return ;
}