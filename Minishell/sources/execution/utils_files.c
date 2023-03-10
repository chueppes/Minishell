#include "../.././includes/minishell.h"

void dup_infile(t_exec *exec_list)
{
	if (exec_list->infile != 0)
	{
		dup2 (exec_list->infile, STDIN_FILENO);
		close(exec_list->infile);
	}
	return ;
}

void dup_outfile(t_exec *exec_list)
{
	if (exec_list->outfile != 0)
	{
		dup2 (exec_list->outfile, STDOUT_FILENO);
		close(exec_list->outfile);
	}
	return ;
}

void close_infile(t_exec *exec_list)
{
	if (exec_list->infile != 0)
		close(exec_list->infile);
	return ;
}

void close_outfile(t_exec *exec_list)
{
	if (exec_list->outfile != 0)
		close(exec_list->outfile);
	return ;
}
