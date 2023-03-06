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
		if (temp_exec->has_doc != 0)
			temp_exec->has_doc = 0;
		if (temp_exec->heredoc_str != NULL)
		{
			free(temp_exec->heredoc_str);
			temp_exec->heredoc_str = NULL;
		}	
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
	int		find_list;
	t_exec	*temp_exec;

	find_list = find_position_open(*comm, i);
	temp_exec = *exec_list;
	str = heredoc_readline(eof);
	str_heredoc(str, exec_list, temp_exec, find_list);
}
