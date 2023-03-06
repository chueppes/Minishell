#include "../.././includes/minishell.h"

char	*heredoc_readline(char *eof)
{
	char *str;
	char *temp;

	str = NULL;
	temp = NULL;
	while (1)
	{
		temp = readline(">");
		if (ft_strncmp(temp, eof, ft_strlen(eof)) == 0)
			break;
		if (!str)
		{
			str = malloc(1);
			*str = '\0';
		}
		str = my_strjoin2(str, temp);
		free(temp);
	}
	free(temp);
//	add_history(str);
	return (str);
}

void str_heredoc(char *str, t_exec **exec_list, t_exec *temp_exec, int find_list)
{
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
		if (temp_exec->infile)
		{
    		close(temp_exec->infile);
			temp_exec->infile = 0;
		}
		if (temp_exec->heredoc_str != NULL)
		{
			free(temp_exec->heredoc_str);
			temp_exec->heredoc_str = NULL;
		}
		temp_exec->has_doc = 1;
		if (str)
		{
			temp_exec->heredoc_str = ft_strdup(str);
			free(str);
		}
		else
		{
			temp_exec->heredoc_str = malloc(1);
			temp_exec->heredoc_str = '\0';
		}
	}
	else
	{
		if (str)
			free(str);
	}
}