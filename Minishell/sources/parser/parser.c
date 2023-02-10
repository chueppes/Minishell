#include "../.././includes/minishell.h"

/*int prepare_exec(t_data *minishell)
{
	t_commands *temp;
	
	minishell->exec_list = create_exec_list(minishell->commands);
	
}*/

int create_list(t_data *minishell)
{
	int i;

	i = -1;
    while (minishell->cmd_split[i])
        lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
//	if (parse_error(minishell))
//		return (-1);
	check_input(minishell);
	check_input2(minishell);
	return (SUCESS);
}

int check_input(t_data *minishell)
{
	t_commands	*temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if (temp->cmd[0] == '>' && temp->cmd[1] == '>')
			temp->token = APPEND_OUTPUT;
		else if (temp->cmd[0] == '>' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_OUTPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '\0')
			temp->token = REDIRECT_INPUT;
		else if (temp->cmd[0] == '<' && temp->cmd[1] == '<')
			temp->token = HEREDOC;
		else if (temp->cmd[0] == '|' && temp->cmd[1] == '\0')
			temp->token = PIPE;
		else
			temp->token = NORMAL_ARG;
		temp = temp->next;
	}
	return (SUCESS);
}

int check_input2(t_data *minishell)
{
	t_commands *temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if (temp->token == APPEND_OUTPUT || temp->token == REDIRECT_INPUT\
		|| temp->token == REDIRECT_OUTPUT)
		{
			temp = temp->next;
			if (temp->token != PIPE && temp->token != APPEND_OUTPUT\
			&& temp->token != REDIRECT_OUTPUT && temp->token != REDIRECT_INPUT\
			&& temp->token != HEREDOC)
				temp->token = FILE_NAME;
		}
		else if (temp->token == HEREDOC)
		{
			temp = temp->next;
			if (temp->token != PIPE && temp->token != APPEND_OUTPUT\
			&& temp->token != REDIRECT_OUTPUT && temp->token != REDIRECT_INPUT\
			&& temp->token != HEREDOC)
				temp->token = DELIMITER;
		}
		temp = temp->next;
	}
	return (SUCESS);
}