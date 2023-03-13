#include "../.././includes/minishell.h"
static void	remove_quotes(t_exec **exec_list);
int			cmd_found_quotes(t_exec *exec_list);
int			cmd_found_quotes2(t_exec *exec_list);

int parser(t_data *minishell)
{
	int i;

	i = -1;
    while (minishell->cmd_split[++i] != NULL)
		lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
	check_input(minishell);
	check_input2(minishell);
    create_exec_list(&minishell->exec_list, minishell->commands);
	prepare_for_execution(&minishell->exec_list);
	remove_quotes(&minishell->exec_list);
	if (parser_error(minishell) == FAILURE)
		return (FAILURE);
	if (cmd_found_quotes(minishell->exec_list) == -1 || cmd_found_quotes2(minishell->exec_list) == -1)
		return (-1);
	search_redirect(&minishell->commands, &minishell->exec_list);
	return (SUCCESS);
}

int	cmd_found_quotes(t_exec *exec_list)
{
	int i;

	while (exec_list)
	{
		i = -1;
		while (exec_list->exec_cmd[0][++i])
		{
			if (is_space(exec_list->exec_cmd[0][i]))
			{
				handle_errors(CMDNOTFOUND_ERR, 127, exec_list->exec_cmd[0]);
				return (-1);
			}
		}
		exec_list = exec_list->next;
	}
	return (0);
}

int	cmd_found_quotes2(t_exec *exec_list)
{
	int i;
	int found_error;
	int alright;

	alright = 0;
	found_error = 0;
	while (exec_list)
	{
		i = -1;
		while (exec_list->exec_cmd[0][++i])
		{
			if (exec_list->exec_cmd[0][i] != '\'' \
			 && exec_list->exec_cmd[0][i] != '\"')
				alright = 1;
		}
		if (alright != 1)
		{
			found_error = 1;
			handle_errors(CMDNOTFOUND_ERR, 127, exec_list->exec_cmd[0]);
		}
		alright = 0;
		exec_list = exec_list->next;
	}
	if (found_error)
		return (-1);
	else	
		return (1);
}


static void	remove_quotes(t_exec **exec_list)
{
	int		i;
	t_exec	*temp;

	temp = *exec_list;
	while (temp)
	{
		i = -1;
		while(temp->exec_cmd[++i])
			temp->exec_cmd[i] = remove_outer_quotes(temp->exec_cmd[i]);
		temp = temp->next;
	}
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
