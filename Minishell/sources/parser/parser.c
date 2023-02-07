#include "../.././includes/minishell.h"

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

int create_list(t_data *minishell)
{
	int i;
	int j; // testes
	t_commands *temp; // testes

    i = -1;
	j = -1; //testes
	while (minishell->cmd_split[++j]) // testes
		printf("%s\n", minishell->cmd_split[j]);
	printf("\n");
    while (minishell->cmd_split[++i])
	{
        lstadd_back_command(&minishell->commands, lstnew_command(minishell->cmd_split[i]));
	}
//	if (parse_error(minishell))
//		return (-1);
	temp = minishell->commands;
	while (temp)
	{
		printf("%s\n", temp->cmd);
		temp = temp->next;
	}
	check_input(minishell);
	check_input2(minishell);
	return (SUCESS);
}

int check_input2(t_data *minishell)
{
	t_commands *temp;

	temp = minishell->commands;
	while (temp != NULL)
	{
		if (temp->token == APPEND_OUTPUT || temp->token == REDIRECT_INPUT || temp->token == REDIRECT_OUTPUT)
		{
			temp = temp->next;
			temp->token = FILE_NAME;
		}
		else if (temp->token == HEREDOC)
		{
			temp = temp->next;
			temp->token = DELIMITER;
		}
		temp = temp->next;
	}
	return (SUCESS);
}