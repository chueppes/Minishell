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