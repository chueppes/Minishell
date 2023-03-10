#include "../.././includes/minishell.h"

int exec_fork_error(t_data *mini)
{
	handle_errors(FORK_ERR, 1, NULL);
	free_all(mini);
	exit(1);
	return (FAILURE);
}

void	has_doc_child(t_exec *exec_list)
{
	close(exec_list->pipe_heredoc[1]);
	dup2(exec_list->pipe_heredoc[0], STDIN_FILENO);
	close(exec_list->pipe_heredoc[0]);
}

void	has_doc_main(t_exec	*exec_list)
{
	close(exec_list->pipe_heredoc[0]);
	ft_putstr_fd(exec_list->heredoc_str, exec_list->pipe_heredoc[1]);
	if (exec_list->heredoc_str && exec_list->heredoc_str[0] != '\0')
		free(exec_list->heredoc_str);
	close(exec_list->pipe_heredoc[1]);
}

void	has_doc_main_single(t_data *minishell)
{
	close(minishell->exec_list->pipe_heredoc[0]);
	ft_putstr_fd(minishell->exec_list->heredoc_str, minishell->exec_list->pipe_heredoc[1]);
	if (minishell->exec_list->heredoc_str && minishell->exec_list->heredoc_str [0] != '\0')
		free(minishell->exec_list->heredoc_str);
	close(minishell->exec_list->pipe_heredoc[1]);
}