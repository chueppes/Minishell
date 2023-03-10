#include "../.././includes/minishell.h"

int parser(t_data *minishell)
{
	int i;

	i = -1;
    while (minishell->cmd_split[++i] != NULL)
		lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
	check_input(minishell);
	check_input2(minishell);
	if (parser_error(minishell) == FAILURE)
		return (FAILURE);
    create_exec_list(&minishell->exec_list, minishell->commands);
	prepare_for_execution(&minishell->exec_list);
	search_redirect(&minishell->commands, &minishell->exec_list);
	return (SUCCESS);
}

int check_input(t_data *minishell)
{
	t_commands	*temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if (temp->cmd[0] == '>' && temp->cmd[1] == '>' && temp->cmd[2] == '\0')
			temp->token = APPEND_OUTPUT;
		else if (temp->cmd[0] == '>' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_OUTPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_INPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '<' && temp->cmd[2] == '\0')
			temp->token = HEREDOC;
		else if (temp->cmd[0] == '|' && temp->cmd[1] == '\0')
			temp->token = PIPE;
		else
			temp->token = NORMAL_ARG;
		temp = temp->next;
	}
	return (SUCCESS);
}

int check_input2(t_data *minishell)
{
	t_commands *temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if ((temp->token == APPEND_OUTPUT || temp->token == REDIRECT_INPUT\
		|| temp->token == REDIRECT_OUTPUT) && temp->next)
		{
			temp = temp->next;
			if (temp->token != PIPE && temp->token != APPEND_OUTPUT\
			&& temp->token != REDIRECT_OUTPUT && temp->token != REDIRECT_INPUT\
			&& temp->token != HEREDOC)
				temp->token = FILE_NAME;
		}
		else if ((temp->token == HEREDOC) && temp->next)
		{
			temp = temp->next;
			if (temp->token != PIPE && temp->token != APPEND_OUTPUT\
			&& temp->token != REDIRECT_OUTPUT && temp->token != REDIRECT_INPUT\
			&& temp->token != HEREDOC)
				temp->token = DELIMITER;
		}
		temp = temp->next;
	}
	return (SUCCESS);
}
