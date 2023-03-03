#include "../.././includes/minishell.h"

char	*heredoc_readline(char *eof)
{
	char *str;
	char *temp;

	str = NULL;
	temp = NULL;
	while (1)
	{
		temp = readline("heredoc>");
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
	return (str);
}

void str_heredoc(char *str, t_exec **exec_list, t_exec *temp_exec, int find_list)
{
	str[ft_strlen(str) - 1] = '\0';
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
		if (temp_exec->outfile)
    		close(temp_exec->outfile);
		temp_exec->heredoc_str = ft_strdup(str);
		free(str);
	}
	else
  	{
		printf("%s\n", str);
		free(str);
  	}
}