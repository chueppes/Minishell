#include "../.././includes/minishell.h"

int find_position_open(t_commands *comm, int i)
{
	int count_pipe;

	count_pipe = 0;
	while (i--)
	{
		if (comm->token == PIPE)
			count_pipe++;
		comm = comm->next;
	}
	return (count_pipe);
}

int open_input(t_commands **comm, t_exec **exec_list, int i, char *file)
{
	t_exec		*temp_exec;
	int			find_list;
  int     temp;

	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
    if (temp_exec->infile != 0)
      close(temp_exec->infile);
		temp_exec->infile = open(file, O_RDONLY, 0444);
	}
	else
  {
		temp = open(file, O_RDONLY, 0444);
    close(temp);
  }
  return (0);
}

int open_output(t_commands **comm, t_exec **exec_list, int i, char *file)
{
	t_exec		*temp_exec;
	int			find_list;
  int     temp;

	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
    if (temp_exec->outfile != 0)
      close(temp_exec->outfile);
		temp_exec->outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	else
  {
		temp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    close(temp);
  }
  return (0);
}

int open_append(t_commands **comm, t_exec **exec_list, int i, char *file)
{
	t_exec	*temp_exec;
	int		find_list;
  int   temp;

	temp_exec = *exec_list;
	find_list = find_position_open(*comm, i);
	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
    if (temp_exec->outfile != 0)
      close(temp_exec->outfile);
		temp_exec->outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	}
	else
  {
		temp = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
    close(temp);
  }
  return (0);
}

void open_heredoc(t_commands **comm, t_exec **exec_list, int i, char *eof)
{
	char	*str;
	char	*temp;
	int		find_list;
	t_exec	*temp_exec;

	str = NULL;
	find_list = find_position_open(*comm, i);
	temp_exec = *exec_list;

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
	str[ft_strlen(str) - 1] = '\0';

	if (exec_list && *exec_list)
	{
		while (find_list--)
			temp_exec = temp_exec->next;
    	if (temp_exec->heredoc != 0)
    		close(temp_exec->outfile);
		temp_exec->heredoc = ft_strdup(str);
		free(str);
	}
	else
  	{
		printf("%s\n", str);
		free(str);
  	}
}
